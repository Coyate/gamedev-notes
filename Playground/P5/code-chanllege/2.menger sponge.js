let angle = 0;
let BBoxes = [];
let BBoxesPrev = [];
function setup() {
    createCanvas(600, 600, WEBGL);
    append(BBoxes, new BBox(0, 0, 0, 300));
    ambientLight(150);
}

function draw() {
    background(12);    
    fill(248, 157, 48);
    noStroke();
    rotateY(angle);
    rotateX(angle * 0.4);
    rotateZ(angle * 0.1);
    angle += 0.0025; 

    let dx = mouseX - width / 2;
    let dy = mouseY - height / 2;
    let v = createVector(dx, dy);
    directionalLight(155, 155, 180, v);

    for (let i = 0; i < BBoxes.length; ++i) {        
        BBoxes[i].display();
    }    
}

function mousePressed() {
    if (mouseButton == LEFT) {
        let len = BBoxes.length;
        for (let j = 0; j < len; ++j) {
            BBoxes = concat(BBoxes, BBoxes[j].generate());
        }
        BBoxesPrev = subset(BBoxes, 0, len);
        BBoxes = subset(BBoxes, len, BBoxes.length);
    } else if (mouseButton == RIGHT) {
        BBoxes = BBoxesPrev;
    }
}

function keyPressed() {
    BBoxes = [];
    append(BBoxes, new BBox(0, 0, 0, 300));
}

class BBox {
    constructor(x, y, z, size) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.r = size;
    }

    display() {
        push();
        translate(this.x, this.y, this.z) ;       
        normalMaterial();
        ambientMaterial(250, 140, 120);
        box(this.r);
        pop();
    }

    generate() {        
        var newBox = [];        
        for (let i = -1; i < 2; ++i) {
            for (let j = -1; j < 2; ++j) {
                for (let k = -1; k < 2; ++k) {
                    let sum = abs(i) + abs(j) + abs(k);
                    // if (sum == 1 || sum == 3) { // star                    
                    // if (sum <= 1) {     // snow
                    if (sum > 1) {   // sponge
                        let newR = this.r / 3;
                        let newX = this.x + i * newR;
                        let newY = this.y + j * newR;
                        let newZ = this.z + k * newR;    
                        append(newBox, new BBox(newX, newY, newZ, newR));       
                    }            
                }
            }
        }
        return newBox;
    }
}

