#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359
#define TWO_PI 6.28318530718

uniform vec2 u_resolution;
uniform float u_time;



float smoothTime(float t) {
    return sin( mod(t * 2.0, 1.0) * PI);
}

float polarFunc(vec2 st) {

    // Number of sides of your shape
    int N = 3;

    // Angle and radius from the current pixel
    float theta = atan(st.y, st.x);
    float r = distance(vec2(0.0), st);

    float a = 0.5 + smoothTime(u_time) / 10.0;

    // heart curve
    float pct = r - a * (1.0 + sin(-theta));

    return  smoothstep(0.01, 0.015, pct);
}



void main(){
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st.x *= u_resolution.x/u_resolution.y;

    // Remap the space to -1. to 1.
    st = st *2.-1.0;
    float offset = 0.5;
    st.y -= offset;

    float gradient = abs(1.0 - st.y) * 1.3;
    vec3 color = vec3(
        0.3 + gradient * 0.5, 
        gradient * 0.2, 
        gradient * 0.2
        );
    
    color = polarFunc(st) > 0.0001? color :  vec3(
    0.75 * gradient, 
    0.3 * gradient, 
    0.3 * gradient);    

    gl_FragColor = vec4(color,1.0);
}
