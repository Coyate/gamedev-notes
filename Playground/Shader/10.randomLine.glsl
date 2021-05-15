#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265358979323846

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float random (in vec2 _st) {
    return fract(sin(dot(_st.xy,
                         vec2(12.9898,0.0)))*
        43758.5453123);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    st *= 10.0;        

    // st.x += sin(u_time) / 100.0;


    vec2 ipos = fract(st);
    vec2 fpos = floor(st);
    

    float pct = smoothstep(0.9, 1.0, random(ipos)) * floor(ipos.y + 1.0);
    
    
    vec3 color = mix(vec3(0.6314, 0.298, 0.298), vec3(0.0, 0.0, 0.0), pct);

    // Maze
    


    gl_FragColor = vec4(vec3(color),1.0);
}
