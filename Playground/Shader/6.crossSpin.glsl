// Author @patriciogv ( patriciogonzalezvivo.com ) - 2015

#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform float u_time;

mat2 scale(vec2 _scale){
    return mat2(_scale.x,0.0,
                0.0,_scale.y);
}

mat2 rotate2d(float _angle){
    return mat2(cos(_angle),-sin(_angle),
                sin(_angle),cos(_angle));
}

float box(in vec2 _st, in vec2 _size){
    _size = vec2(0.5) - _size*0.5;
    vec2 uv = smoothstep(_size,
                        _size+vec2(0.001),
                        _st);
    uv *= smoothstep(_size,
                    _size+vec2(0.001),
                    vec2(1.0)-_st);
    return uv.x*uv.y;
}

float cross(in vec2 _st, float _size){
    return  box(_st, vec2(_size,_size/4.)) +
            box(_st, vec2(_size/4.,_size));
}

void main(){
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(0.95, 0.9, 0.9);
    
    vec2 translate = vec2(cos(u_time * 2.0),sin(u_time * 2.0));
    st -= vec2(0.5);    
    st += translate * 0.35;
    st = scale( vec2(sin(u_time)+1.5) ) * rotate2d(u_time * 10.0) * st;
    st += vec2(0.5);
    
    // Add the shape on the foreground
    color = mix(color, vec3(0.9412, 0.2941, 0.1333), cross(st,0.2));

    gl_FragColor = vec4(color,1.0);
}
