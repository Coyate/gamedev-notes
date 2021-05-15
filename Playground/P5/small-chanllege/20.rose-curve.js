let maxTheta;
let alpha;    
let thetaStep;
let n;

function setup() {
    createCanvas(700, 700);
    noFill();
    maxTheta = 2 * PI;
    alpha = 400;    
    thetaStep = PI / 100;
    n = 1.0;
}


function draw() {
    background(48);

    push();
    translate(width / 2, height / 2);
    stroke(250, 150, 00);
    

    beginShape();
    for(var theta = 0; theta <= maxTheta; theta += thetaStep) {
        // the formula    
        var r =  alpha * sin(n * theta);
        var x = r * cos(theta);
        var y = r * sin(theta);
        vertex(x, y);
    }
    endShape();
    pop();

    n += 0.01;
}