var points = [];
var step = 15;
var dir = 0.05;

function setup() {
    createCanvas(512, 512);
    for(var i = 0; i < width / step; ++i) {
        points[i] = [];
        for(var j = 0; j < height / step; ++j) {
            points[i][j] = 0;
        }
    }       
    noStroke();
}


function draw() {
    background(0);
    // step += dir;
    // if(step >= 15 || step <= 10)
    //     dir = -dir;
    for(var i = 0; i < points.length; ++i) {
        for(var j = 0; j < points[i].length; ++j) {
            var x = i * step + step / 2;
            var y = j * step + step / 2
            var d = dist(mouseX, mouseY, x, y);
            // var d = dist(width / 2, height / 2, x, y);
            points[i][j] = map(d, 0, 250, 255, 255);
            var size = map(d, 0, 300, 0, step * 1.7);
            fill(points[i][j]);
            ellipse(x, y, size);
            
        }
    }
}