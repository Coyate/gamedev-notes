

function setup() {
    createCanvas(600, 600);
}

function draw() {
    var s = 'The quick brown fox jumped over the lazy dog.';
    textSize(32);
    fill(250);
    text(s, 10, 10, 200, 200); // Text wraps within text box
}


class Camera {
    constructor(x, y, z) {
        this.postion = createVector(position.x, position.y, position.z);
        this.up = createVector(0.0, 1.0, 0.0);
        this.righ = createVector()
    }
}