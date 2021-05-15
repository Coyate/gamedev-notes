
#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.141592653

uniform vec2 u_resolution;
uniform float u_time;

vec2 brickTile(vec2 _st, float _zoom){
    _st *= _zoom;

    // Here is where the offset is happening
    
    float time = sin(u_time * 2.0);
    float at = fract(u_time / PI * 2.0);
    _st.x += 
    (step(1.0, mod(_st.y, 2.0)) * at
    - step(1.0, mod(_st.y + 1.0, 2.0)) * at)
    * step(0., time);;
    

    _st.y += 
    (step(1.0, mod(_st.x, 2.0)) * at
    -step(1.0, mod(_st.x + 1.0, 2.0)) * at)
    * step(0., -time);

    return fract(_st);
}

float cricle(vec2 _st, float _size) {    
    _st *= 2.0;
    return smoothstep(_size, _size + 0.01, distance(_st, vec2(1.0)));
}

void main(void){
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(0.3725, 0.7725, 0.6745);

    // Apply the brick tiling
    st = brickTile(st, 5.0);

    color = mix(vec3(0.8745, 0.8706, 0.7176),  color, vec3( cricle(st,0.35))); 

    // Uncomment to see the space coordinates
    // color = vec3(st,0.0);

    gl_FragColor = vec4(color,1.0);
}