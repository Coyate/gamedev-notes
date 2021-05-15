let maxAngle;
let alpha;    
let angleStep;
let rotateAngle;
let rotateStep;

function setup() {
    createCanvas(512, 512);
    stroke(250, 150, 00);

    maxAngle = PI * 10;
    alpha = 10;    
    angleStep = PI / 100;
    rotateAngle = 0;
    rotateStep = 0.1;
}

function draw() {
    background(48);

    push();
    translate(width / 2, height / 2);
    rotate(rotateAngle);

    for(var angle = 0; angle <= maxAngle; angle += angleStep) {
        // the formula    
        var r = angle  * alpha;
        var r2 = (angle + angleStep)* alpha;

        var x1 = r * cos(angle);
        var y1 = r * sin(angle);
        var x2 = r2 * cos(angle + angleStep);
        var y2 = r2 * sin(angle + angleStep);

        line(x1, y1, x2, y2);
    }
    pop();

    rotateAngle += rotateStep;

}