function setup() {
    createCanvas(512, 512, WEBGL);
}

var sphereSize = 10;
var flag = 0;

function draw() {
    background(72);

    push();
    fill(50, 200, 100, 20);
    stroke(200);
    strokeWeight(1.5);
    rotateX(-frameCount / 500);
    rotateZ(frameCount / 500);
    rotateY(frameCount / 500);
    box(100);
    pop();


    push();
    noFill();
    strokeWeight(0.5);
    stroke(150, 200, 100, 100);
    rotateY(frameCount / 500);
    
    if(flag == 0) {
        sphereSize += 2;
        if(sphereSize == 500)
            flag = 1;
    } else {
        sphereSize -= 2;
        if(sphereSize == 0)
            flag = 0;
    }
    sphere(sphereSize);
    pop();
}
