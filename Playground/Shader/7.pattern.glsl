// Author @patriciogv - 2015

#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform float u_time;

float circle(in vec2 _st, in float _radius){
    vec2 l = _st-vec2(0.5);
    return 1.-smoothstep(_radius-(_radius*0.01),
                         _radius+(_radius*0.01),
                         dot(l,l)*4.0);
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

vec2 rotate2d(vec2 _st, float _angle){
    _st -= vec2(0.5);    
    _st *= 
     mat2(cos(_angle),-sin(_angle),
                sin(_angle),cos(_angle));
    _st += vec2(0.5);
    return _st;
}

vec2 offset(vec2 _st, vec2 _offset){
    vec2 uv;

    if(_st.x>0.5){
        uv.x = _st.x - 0.5;
    } else {
        uv.x = _st.x + 0.5;
    }

    if(_st.y>0.5){
        uv.y = _st.y - 0.5;
    } else {
        uv.y = _st.y + 0.5;
    }

    return uv;
}

float boxOutline(vec2 _st, vec2 _size, float _smoothEdges){
    _size = vec2(0.5)-_size*0.5;
    vec2 aa = vec2(_smoothEdges*0.5);
    vec2 uv = smoothstep(_size,_size+aa,_st);
    uv *= smoothstep(_size,_size+aa,vec2(1.0)-_st);
    return uv.x*uv.y;
}

void main() {
	vec2 st = gl_FragCoord.xy/u_resolution;
    
    vec3 bg =  vec3(0.7922, 0.7922, 0.7922);
    vec3 line = vec3(0.3882, 0.3843, 0.3765);
    vec3 color = bg;

    float size = 0.15 + abs(sin(u_time)) * 0.05;
    st *= 7.0;      // Scale up the space by 3    
    
    st = fract(st);    
    // st = rotate2d(st, u_time * 10.0);// 
    color = mix(color, line, box(st, vec2(0.98 ))) ;        

    // st /= 10.0;    
    // st += vec2(0., 0.);
    // st *= 10.0;    
    
    st = offset(st, vec2(0.5, 0.5));
    st = rotate2d(st, PI * 0.25);    
    color = mix(color, bg, box(st, vec2(size))) ;        
    color = mix(color, line, box(st, vec2(size - 0.05))) ;            
    // Now we have 3 spaces that goes from 0-1



	gl_FragColor = vec4(color,1.0);
}