let step = 0.01;
let speed = 0.0001;
function setup() {
    createCanvas(512, 512);    
}


function draw() {
    background(144);
    noStroke();
    step += speed;    
    if (step > 0.25) {        
        speed = -0.0001;        
    } else if (step < 0.01) {
        speed = 0.0001;        
    }
    for(ribbon = 0.0 ; ribbon <= 1.0; ribbon += step * 2) {
        fill(100, 225, 100);
        rect(0, height * ribbon, width , height * step);

        fill(255);
        rect(width * ribbon, 0, width * step , height);        
    }
}


