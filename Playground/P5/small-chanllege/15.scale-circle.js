var angle = 0;
var diameter;
function setup() {
    createCanvas(700, 400);
    noStroke();
    diameter = height - 50;
    fill(255, 204, 0);
}


function draw() {
    background(48);

    var d1 = sin(radians(angle)) * diameter / 2 + diameter / 2 + 10;
    var d2 = sin(radians(angle) + PI / 2) * diameter / 2 + diameter / 2 + 10;
    var d3 = sin(radians(angle) + PI) * diameter / 2 + diameter / 2 + 10;

    ellipse(0, height / 2, d1);
    ellipse(width / 2, height / 2, d2);
    ellipse(width, height / 2, d3);

    angle += 1;
}