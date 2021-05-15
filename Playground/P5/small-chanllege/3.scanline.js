function setup() {
    createCanvas(400, 400);
    // noLoop();
    // frameRate(20);
}

var y = 100;

function draw(){
    background(0);
    y -= 0.1;
    if(y < 0) 
        y = height;
    stroke(255);
    lines = 50;
    step = height / lines;
    for(i = 0; i < lines; ++i) {
        line(0, y - i * step, width, y - i * step + step * 2);
        line(0, y + i * step, width, y + i * step + step * 2);
    }
}

function mousePressed() {
    redraw();    
}
function mouseMoved() {
    redraw();
}