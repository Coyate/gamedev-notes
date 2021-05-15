
#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359
#define TWO_PI 6.28318530718

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main(){
	vec2 st = gl_FragCoord.xy/u_resolution;
    
    float pct = 0.0;
    
    pct = distance(st,vec2(0.5));

    // vec2 toCenter = vec2(0.5)-st;
    // pct = length(toCenter);

    pct = floor(pct * 35.0) / 35.0 - 0.15;    
    float vari = sin( mod(u_time / 3.0, 1.0) * PI);
    float color = clamp(pct + vari, 0.0, 1.0);

	gl_FragColor = vec4(
        0.5 * color, 
        0.5 + 0.8   * color, 
        0.3 + 0.3 * color, 
        1.0 );
}