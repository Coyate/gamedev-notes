var step = 50;
var theta = 0;

function setup() {
    createCanvas(512, 512);
}


function draw() {
    background(0);
    

     for(var i = 0; i * step <= width; ++i) {
        for(var j = 0; j * step <= height; ++j) {
            var x = cos(radians(theta)) * 50;
            var y = sin(radians(theta)) * 50;
            stroke(255, 50);
            theta += 0.005;
            line(width / 2 + x, height / 2 + y, (i + 0.5)  * step, (j + 0.5) * step);       
            noStroke();
            fill(155, 150);
            rect((i + 0.5) * step, (j + 0.5)  * step, 3, 3);
        }
    } 
}