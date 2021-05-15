
#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359
#define TWO_PI 6.2831853071
uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

#define t u_time
#define r u_resolution.xy

// origin : https://www.shadertoy.com/view/XsXXDn
void main(){
    vec3 color;
    float len = 0.0;
    float z = t;
    float vari = sin( mod(u_time / 3.0, 1.0) * PI);
    for(int i=0;i<3;i++){
        vec2 uv = vec2(0.0); // (0)
        vec2 p = gl_FragCoord.xy/r; // (0.0 ~ 1.0)
        uv = p; // (0.0 ~ 1.0)
        p -= .5; // (-0.5 ~ 0.5)
        p.x *= r.x/r.y; // (-0.75 ~ 0.75) in 4:3 screen        
        
        len = length(p); // l <= 1.0

        vari += 0.1;        

        uv += 
        p / len * // strench
        (vari + 1.0) * 
        cos( mod(u_time / 3.0, 1.0) * PI);
        ;

        color[i]= 0.01 / len / length(mod(uv, 1.) - 0.5);
        
    }
    gl_FragColor=vec4(color, t);     // t : fade in
}