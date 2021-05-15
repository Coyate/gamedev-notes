
#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;


#define PI_TWO			1.570796326794897
#define PI				3.141592653589793
#define TWO_PI			6.283185307179586

vec2 coord(in vec2 p) {
	p = p / u_resolution.xy;
	// correct aspect ratio
	if (u_resolution.x > u_resolution.y) {
		p.x *= u_resolution.x / u_resolution.y;
		p.x += (u_resolution.y - u_resolution.x) / u_resolution.y / 2.0;
	} else {
		p.y *= u_resolution.y / u_resolution.x;
		p.y += (u_resolution.x - u_resolution.y) / u_resolution.x / 2.0;
	}
	// centering
	p -= 0.5;
	p *= vec2(-1.0, 1.0);
	return p;
}

float random (vec2 st) {
    return fract(sin(dot(st.xy,
                         vec2(12.9898,78.233) + floor(u_time)))*
        43758.5453123);
}

#define rx 1.0 / min(u_resolution.x, u_resolution.y)
#define uv gl_FragCoord.xy / u_resolution.xy
#define mx coord(u_mouse) 




void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;

    st *= 10.0; // Scale the coordinate system by 10
    vec2 ipos = floor(st);  // get the integer coords
    vec2 fpos = fract(st);  // get the fractional coords

    // Assign a random value based on the integer coord
	vec3 c1 = vec3(
		abs(cos(mx.x)),
		abs(sin(mx.y)),
		abs(sin(u_time))
	);
    vec3 c2 =  vec3(
        abs(sin(mx.x)),
		abs(cos(mx.y)),
		abs(cos(u_time)));
    vec3 color = mix(c1, c2, random( ipos ));    

    gl_FragColor = vec4(color,1.0);
}
