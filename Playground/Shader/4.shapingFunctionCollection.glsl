#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359
#define TWO_PI 6.28318530718

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plot(vec2 st, float y){
                
    float r =  
    smoothstep( y - 0.005, y, st.y) -
    smoothstep( y, y + 0.005, st.y);
    return r;
}

// http://www.flong.com/texts/code/shapers_poly/

// double-cubic seat ：双段控制，可以用 a,b 控制折转点
float doubleCubicSeat (float x, float a, float b){
  
  float epsilon = 0.00001;
  float min_param_a = 0.0 + epsilon;
  float max_param_a = 1.0 - epsilon;
  float min_param_b = 0.0;
  float max_param_b = 1.0;
  a = min(max_param_a, max(min_param_a, a));  
  b = min(max_param_b, max(min_param_b, b)); 
  
  float y = 0.0;
  if (x <= a){
    y = b - b * pow(1.0-x/a, 3.0);
  } else {
    y = b + (1.0-b)*pow((x-a)/(1.0-a), 3.0);
  }
  return y;
}


//---------------------------------------------------------------
float doubleCubicSeatWithLinearBlend (float x, float a, float b){

  float epsilon = 0.00001;
  float min_param_a = 0.0 + epsilon;
  float max_param_a = 1.0 - epsilon;
  float min_param_b = 0.0;
  float max_param_b = 1.0;
  a = min(max_param_a, max(min_param_a, a));  
  b = min(max_param_b, max(min_param_b, b)); 
  b = 1.0 - b; //reverse for intelligibility.
  
  float y = 0.0;
  if (x<=a){
    y = b*x + (1.0-b)*a*(1.0-pow(1.0-x/a, 3.0));
  } else {
    y = b*x + (1.0-b)*(a + (1.0-a)*pow((x-a)/(1.0-a), 3.0));
  }
  return y;
}



// sine simulate!
float blinnWyvillCosineApproximation (float x){
    float x2 = x*x;
    float x4 = x2*x2;
    float x6 = x4*x2;
  
    float fa = ( 4.0/9.0);
    float fb = (17.0/9.0);
    float fc = (22.0/9.0);
  
    float y = fa*x6 - fb*x4 + fc*x2;
    return y;
}

// Double-Odd-Polynomial Seat

float doubleOddPolynomialSeat (float x, float a, float b, int n){

  float epsilon = 0.00001;
  float min_param_a = 0.0 + epsilon;
  float max_param_a = 1.0 - epsilon;
  float min_param_b = 0.0;
  float max_param_b = 1.0;
  a = min(max_param_a, max(min_param_a, a));  
  b = min(max_param_b, max(min_param_b, b)); 

  int p = 2 * n + 1;
  float y = 0.0;
  if (x <= a){
    y = b - b * pow(1.0-x/a, float(p));
  } else {
    y = b + (1.0-b)*pow((x-a)/(1.0-a), float(p));
  }
  return y;
}


void main(){
	vec2 st = gl_FragCoord.xy/u_resolution;        
    vec2 ms = u_mouse / u_resolution;
    vec3 color = vec3(0.3, 0.35 - 0.5 * st.x, 0.7);

    float y1 = st.x;
    float y2 = pow(st.x, 5.0 * ms.x);
    float y3 = smoothstep(0.0, ms.x, st.x);
    float y4 = sin(0.5 * st.x * PI);
    float y5 = blinnWyvillCosineApproximation(st.x);    
    float y6 = doubleCubicSeat(st.x, ms.x, ms.y);    
    float y7 = doubleCubicSeatWithLinearBlend(st.x, ms.x, ms.y);
    float y8 = doubleOddPolynomialSeat(st.x, 0.5, 0.5, int(ms.x * 20.0));
    float pct =
    plot(st, y1) +
    plot(st, y2) +
    plot(st, y3) + 
    plot(st, y4) + 
    plot(st, y5) + 
    plot(st, y6) + 
    plot(st, y7) + 
    plot(st, y8);
    

    
    color +=  pct * vec3(0.8, 0.3, 0.1); 



	gl_FragColor = vec4(vec3(color), 1.0);
}
