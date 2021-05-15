var points = [];
var step = 10;

function setup() {
    createCanvas(512, 512);
    for(var i = 0; i < width / step; ++i) {
        points[i] = [];
        for(var j = 0; j < height / step; ++j) {
            points[i][j] = 0;
        }
    }       
}

function draw() {
    background(32);
    for(var i = 0; i < points.length; ++i) {
        for(var j = 0; j < points[i].length; ++j) {
            var x = i * step + step / 2;
            var y = j * step + step / 2
            var d = dist(mouseX, mouseY, x, y);
            points[i][j] = map(d, 0, 200, 255, 10);
            stroke(points[i][j]);
            ellipse(x, y, 2);
            // point(x, y);
        }
    }
}