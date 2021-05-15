// 内摆线

let stepTheta;
let maxTheta;
let r;  // 小圆半径
let k; // 大圆相对于小圆半径的倍数


function setup() {
    createCanvas(1100, 1100);
    noFill();
    maxTheta = 0;
    stepTheta = PI / 100;

    r = 50;
    k = 1;
}

function draw() {
    background(48);
    
    // if(maxTheta <= 3 * PI) 
    maxTheta += stepTheta;

    k += 0.01;
    push();
    translate(width / 2, height / 2);
    
    stroke(250, 150, 0);
    noFill();
    ellipse(0, 0, r * k * 2);
    beginShape();
    for(var theta = 0; theta <= maxTheta; theta += stepTheta) {
        var x = r * (k - 1) * cos(theta) + r * cos((k - 1) * theta);
        var y = r * (k - 1) * sin(theta) - r * sin((k - 1) * theta);
        vertex(x, y);
    }
    endShape();

    fill(250, 150, 0);
    ellipse(r * (k - 1) * cos(maxTheta) + r * cos((k - 1) * maxTheta),
            r * (k - 1) * sin(maxTheta) - r * sin((k - 1) * maxTheta), 10);
    pop();
}