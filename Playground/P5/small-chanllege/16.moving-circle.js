function setup() {
    createCanvas(512, 512);
    noStroke();
}

var angle = 0;

function draw() {
    background(48);
    var rectSize = 200;
    var circleSize = 100;
    fill(255);


    push();
    translate(width / 2, height / 2);
    // rotate(angle / 2);
    rect( - rectSize / 2 + 10,  - rectSize / 2 + 10, rectSize - 20, rectSize - 20);
    pop();

    var offset1 = sin(angle) * rectSize / 2.5;
    var offset2 = sin(angle + PI / 3) * rectSize / 2.5;
    var offset3 = sin(angle + PI / 2) * rectSize / 2.5;
    var offset4 = sin(angle + PI / 7) * rectSize / 2.5;
    
    
    fill(50, 150, 255);

    // up
    ellipse(width / 2 + offset1, height / 2 - rectSize + circleSize / 2, circleSize - 20);

    // down
    ellipse(width / 2 + offset2, height / 2 + rectSize - circleSize / 2, circleSize - 20);

    
    fill(255, 150, 50);
    
    // left
    ellipse(width / 2  - rectSize + circleSize / 2, height / 2 + offset3, circleSize - 20);

    // right
    ellipse(width / 2  + rectSize - circleSize / 2, height / 2 + offset4, circleSize - 20);

    angle += 0.03;
}