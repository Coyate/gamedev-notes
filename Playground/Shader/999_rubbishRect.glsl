
#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359
#define TWO_PI 6.2831853071
uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float rect(vec2 start, vec2 size, vec2 st) {
    st -= start;    
    vec2 bottomLeft = step(vec2(0.0), st);
    vec2 topRight = 1.0 - step(size, st);
    return bottomLeft.x * bottomLeft.y * topRight.x * topRight.y;
}


float rectSmooth(vec2 start, vec2 size, vec2 st) {
    st -= start;
    vec2 bottomLeft = smoothstep(vec2(0.0), vec2(0.0) + 0.01, st);
    vec2 topRight = 1.0 - smoothstep(size, size + 0.01, st);
    return bottomLeft.x * bottomLeft.y * topRight.x * topRight.y;
}

float rectOutline(vec2 start, vec2 size, float stroke, vec2 st) {  
    st -= start;   

    vec2 bottomLeft = step(vec2(0.0), st);
    vec2 topRight = 1.0 - step(size, st);
    
    vec2 innerBottomLeft = 1.0 - step( stroke, st);
    vec2 innerTopRight = step(stroke + size, st);

    return bottomLeft.x * bottomLeft.y * topRight.x * topRight.y;
}


void main(){
	vec2 st = gl_FragCoord.xy/u_resolution;    
    
    float timeBeat = sin( mod(u_time / 3.0, 1.0) * PI);
    

    float pct = 0.0;
    for (float i = .0; i < 50.0; i+=1.0) {
        pct += rectSmooth(vec2(0.02 * i), vec2(0.025 * i * timeBeat), st); 
        // pct += smo(vec2(0.075 * i), vec2(0.075 * i * (1.0 + timeBeat)), 0.1, st);
    }

    // vec2 toCenter = vec2(0.5)-st;
    // pct = length(toCenter);    

    float color = clamp(pct /*+ timeBeat*/, 0.0, 1.0);

	gl_FragColor = vec4(
        0.1 + 0.5 * pct, 
        0.5 + 0.8   * color, 
        0.3 + 0.3 * color, 
        1.0 );
}