var step = 40;
var dots = [];
var nums;
function setup() {
    createCanvas(512, 512);
    var index = 0;
    for(var i = 0; i < width / step; ++i) {
        for(var j = 0; j < height / step; ++j) {
            dots[index++] = new dot((i + 0.5) * step, (j + 0.5) * step, 0, 0,   random(0.08, 0.5), step);
        }
    }
    nums = index;
    noStroke();
}

function draw() {
    background(48);
    for(var i = 0; i < nums; ++i) {
        dots[i].update();
        dots[i].draw();
    }
}

function dot(_x, _y, _xOffset, _yOffset, _speed, _step) {
    this.x = _x;
    this.y = _y;
    this.xOffset = _xOffset;
    this.yOffset = _yOffset;
    this.xDir = random(0, 1) > 0.5? 1 : -1;
    this.yDir = random(0, 1) > 0.5? 1 : -1;
    this.speed = _speed;
    this.step = _step;
    this.c =color(random(100, 200),  random(100, 200), random(100, 200));
}

dot.prototype.update = function() {
    if(abs(this.xOffset) >= step)
        this.xDir = - this.xDir;
    if(abs(this.yOffset) >= step)
        this.yDir = - this.yDir;
    this.xOffset += this.xDir * this.speed;
    this.yOffset += this.yDir * this.speed;
}

dot.prototype.draw = function() {
    fill(this.c);
    ellipse(this.x + this.xOffset, this.y + this.yOffset,  7, 7);
}