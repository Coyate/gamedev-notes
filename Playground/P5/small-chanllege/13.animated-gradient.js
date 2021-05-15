var index;
var dir;
var step;
var angle;
function setup() {
    createCanvas(512, 512);    
    // Hue, Satruation, Brightness
    // colorMode(HSB, width * 7, height, height);
    noStroke();
    index = 0;
    dir = 1;
    step = 3;
    angle = 0;
}



function draw() {

    // dir
    index += dir * step;
    if(index >= width || index <= 0) {
        dir = -dir;
    }

    // RGB blend

    var c1 = color(0, 255, 148);
    var c2 = color(0, 148, 255);
    var c;
    if(dir > 0) {
        c = lerpColor(c1, c2, 1 - index / width);
    } else {
        c = lerpColor(c1, c2, index / width);
    }
    fill(c);    
    rect(index, 0, step, height / 2);
    rect(width - index  - step, height / 2, step, height / 2);


    /// Hue blend
/* 
    var c;
    if(dir > 0) {
        c =color(index + width * 3, height, height);
    } else {
        c = color(width * 4 - index, height, height);
    }
    fill(c);
    rect(index, 0, step, height / 2);
    rect(width - index  - step, height / 2, step, height / 2); */
    
    // grid
    // var yStep = 10;
    // for(var j = 0; j <= height / yStep; j += 2) {
    //     rect(index, j * yStep, step, yStep);
    //     rect(width - index  - step,  (j + 1) * yStep, step, yStep);
    // }


}