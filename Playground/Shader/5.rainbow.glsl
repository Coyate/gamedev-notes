#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;
uniform vec2 u_mouse;

vec3 rgb2hsb( in vec3 c ){
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz),
                 vec4(c.gb, K.xy),
                 step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r),
                 vec4(c.r, p.yzx),
                 step(p.x, c.r));
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)),
                d / (q.x + e),
                q.x);
}

//  Function from Iñigo Quiles
//  https://www.shadertoy.com/view/MsS3Wc
vec3 hsb2rgb( in vec3 c ){
    vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),
                             6.0)-3.0)-1.0,
                     0.0,
                     1.0 );
    rgb = rgb*rgb*(3.0-2.0*rgb);
    return c.z * mix(vec3(1.0), rgb, c.y);
}

// Double-Odd-Polynomial Seat

float doubleOddPolynomialSeat (float x, float a, float b, int n){

  float epsilon = 0.00001;
  float min_param_a = 0.0 + epsilon;
  float max_param_a = 1.0 - epsilon;
  float min_param_b = 0.0;
  float max_param_b = 1.0;
  a = min(max_param_a, max(min_param_a, a));  
  b = min(max_param_b, max(min_param_b, b)); 

  int p = 2 * n + 1;
  float y = 0.0;
  if (x <= a){
    y = b - b * pow(1.0-x/a, float(p));
  } else {
    y = b + (1.0-b)*pow((x-a)/(1.0-a), float(p));
  }
  return y;
}

float rectSmooth(vec2 start, vec2 size, vec2 st) {
    st -= start;
    vec2 bottomLeft = smoothstep(vec2(0.0), vec2(0.0) + 0.1, st);
    vec2 topRight = 1.0 - smoothstep(size - 0.1, size, st);
    return bottomLeft.x * bottomLeft.y * topRight.x * topRight.y;
}

void main(){
    vec2 st = gl_FragCoord.xy/u_resolution;
    vec3 color = vec3(0.0);


    // We map x (0.0 - 1.0) to the hue (0.0 - 1.0)
    // And the y (0.0 - 1.0) to the brightness
    float b = rectSmooth(vec2(0.0, 0.0), vec2(1.0, 1.0), st);
    float h = -st.y + u_time * 0.75;
    b = doubleOddPolynomialSeat(b, 0.5, 1.0, 0);
    b *= 0.75;
    h = h * 2.0;
    color = hsb2rgb(vec3(h, 1.0, b));

    gl_FragColor = vec4(color,1.0);
}