let gA = 160;
let gB = 100;
let gC0 = 0;
function setup() {
    createCanvas(600, 600);
    gC0 = random(0, 2*PI);
}

function draw() {    
    background(48);
    push();

    translate(width/2, height/2);        
    stroke(200, 100, 20);
    strokeWeight(1);    
    line(-width/2, 0, width/2, 0);
    line(0, -height / 2, 0, height / 2);
    strokeWeight(2);    
    moveTriangle(gA, gB);    
    kEllipse(gA, gB);            

    pop();
}

function kEllipse(a, b) {
    let yLast = 0;    
    for(let x = -a + 1; x <= a; x +=1) {        
        y_2 = (1 - x * x / a / a) * b * b;                
        y = abs(sqrt(y_2));
        line(x - 1, yLast, x, y);        
        line(x - 1, -yLast, x, -y);
        yLast = y;
    }
}

function getRadius(a, b, theta) {
    return abs(sqrt((a * a * b * b) / (b * b * cos(theta) * cos(theta) + a * a * sin(theta)* sin(theta))));
}

function moveTriangle(a, b) {
    
    gC0 += 0.001 * PI;
    gC0 %= 2 * PI;
    let c1 = gC0 + PI * 1 / 3;
    let c2 = c1 + PI * 2 / 3;
    c1 %= 2 * PI;
    c2 %= 2 * PI;

    let r0 = getRadius(a, b, gC0);
    let r1 = getRadius(a, b, c1);
    let r2 = getRadius(a, b, c2);
    noFill();    
    beginShape(TRIANGLE_STRIP);    
    vertex(r0 * cos(gC0), r0 * sin(gC0));
    vertex(r1 * cos(c1), r1 * sin(c1));
    vertex(r2 * cos(c2), r2 * sin(c2));
    endShape();
}