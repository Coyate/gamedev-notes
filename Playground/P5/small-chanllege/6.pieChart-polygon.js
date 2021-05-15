function setup() {
    createCanvas(512, 600);
    noStroke();
}

var data = [63, 27, 23, 45, 62, 35, 72, 33];

function draw() {
    background(32);
    push();
    translate(width / 2, height / 6);
    rotate(frameCount / 100);
    pieChart(0, 0, 120, data);
    pop();

    for(var j = 0; j < 3; ++j) {
        for(var i = 0; i < 3; ++i) {
            push();
            fill(map(i + j * 3, 0, 6, 56, 160));
            var x = map(i, -1, 3, 0, width);
            var y = map(j, -1, 2, height / 6, height * 7 / 8);
            translate(x, y);
            rotate(frameCount * (6 - i - j) / 300);
            polygon(0, 0, 60, 3 + i + j * 3);
            pop();
        }
    }
}

function pieChart(x, y, diameter, data) {
    var angle = 0;
    for(i = 0; i < data.length; i++) {
        fill(map(i, 0, data.length, 56, 160));
        arc(x, y, diameter, diameter, angle, angle + radians(data[i]));
        angle += radians(data[i]);
    }
}

function polygon(x, y, radius, nvertex) {
    var angle = TWO_PI / nvertex;
    beginShape();
    for(var theta = 0; theta < TWO_PI; theta += angle) {
        vertex(x + cos(theta) * radius, y + sin(theta) * radius);
    }
    endShape(CLOSE);
}