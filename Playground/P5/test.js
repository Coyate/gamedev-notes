
let size = 50;
let add = 0.5;

let b;


function setup() {
  createCanvas(500, 500);
  b = new ball(100, 100, color(1, 1, 1));
}

function draw() {
  background(48);
  fill(200, 100, 150);
  noStroke();
  ellipse(width / 2, height / 2, size);
  size += add;
  if(size > 100 || size < 50)
    add = -add;
  
    b.display();
}

class ball {
  constructor(x, y, color) {
    this.x = x;
    this.y = y;
    this.color = color;
    this.size = random(50, 100);
  }

  display() {
    ellipse(this.x, this.y, this.size);
  }
}