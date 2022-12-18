let player
let level = []
let w = 600
let h = 600
let axis 

function setup() {  
  createCanvas(w, h)
  //level.push(1);  
  level.push(new Rect(0, 0, w, 10))
  player = new Player()

}

function draw() {    
  background(160);
  
  translate(w/2, h*3/5)
  rotate(3.14)
  level.forEach(e => {
	e.draw()	
  });
  
  player.update()
  player.draw()
}



class Player {
	constructor() {	
		this.pos = createVector(0, 0)	
	}

	update() {
		this.pos.add(axis)
	}

	draw() {
		noStroke()
		fill(200, 100, 50)
		ellipse(this.pos.x, this.pos.y + 45, 30, 50)
	}

}


class Rect {
	constructor(x, y, w, h) {
		this.x = x
		this.y = y
		this.w = w
		this.h = h
	} 

	draw() {
		noStroke()
		fill(250, 200, 10);
		rect(this.x - this.w/2, this.y + this.h, this.w, this.h)
	}

}


function keyPressed() {        
	let x = 0
	let y = 0
	if (keyCode == UP_ARROW) {        
		y = 1
	} else if (keyCode == DOWN_ARROW) {
		y = -1
	} 
	if (keyCode == RIGHT_ARROW) {
		x = 1
	} else if (keyCode == LEFT_ARROW) {
		x = -1
	} 	 
	axis = createVector(-x, -y)
}

