#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359
#define TWO_PI 6.28318530718

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;


float func(float x) {
    // a 2D Cartesian function, return y = f(x)
    // float y = x;    

    float y = 0.0;
    for (float i = 5.0; i <= 10.0; i+=1.0) {
        y += sin(i * x * 3.0 + u_time * 10.0) * 0.3; // * mod(u_time, 0.1);
    }
    
    return y;
}

float plot(vec2 st){
    
    // modify x range
    st.x *= 10.0;

    // modify y range
    st.y = st.y * 2.0 - 1.0;

    float y = func(st.x);    

    float r =  smoothstep( y-0.1, y, st.y) -
            smoothstep( y, y+0.1, st.y);
    return r;
}



void main(){
	vec2 st = gl_FragCoord.xy/u_resolution;        

    vec3 color = vec3(0.3, st.x, 0.7);

    float pct = plot(st);
    
    color +=  pct * vec3(0.8, 0.3, 0.1); 



	gl_FragColor = vec4(vec3(color), 1.0);
}

/*
bool pct(vec2 p) {
    bool k = abs(p.x - p.y) < 0.001;
    return k;
}

    // float color = pct(st) ? 1.0: st.x;
*/