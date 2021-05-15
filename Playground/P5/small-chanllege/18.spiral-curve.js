let maxAngle;
let timeStep;
let alpha; 
let angleStep;

function setup() {
    createCanvas(512, 512);
    maxTheta = PI;
    timeStep = PI / 30;
    alpha = 10;    
    thetaStep = PI / 100;
}

function draw() {
    background(48);

    push();
    translate(width / 2, height / 2);
    stroke(250, 150, 00);
    for(var angle = 0; angle <= maxTheta; angle += thetaStep) {
    
        // the formula    
        var r = angle  * alpha;
        var r2 = (angle + thetaStep)* alpha;

        var x1 = r * cos(angle);
        var y1 = r * sin(angle);
        var x2 = r2 * cos(angle + thetaStep);
        var y2 = r2 * sin(angle + thetaStep);

        line(x1, y1, x2, y2);
    }
    
    noStroke();
    fill(250, 150, 00);
    ellipse(alpha * maxTheta * cos(maxTheta) , alpha * maxTheta 
    * sin(maxTheta), 10);

    pop();

    maxTheta += timeStep;
}