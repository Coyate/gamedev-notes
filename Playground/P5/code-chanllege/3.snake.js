 
let grid = 20;
let foodnum = 10;
let GameOver;
var foods = [];
var snake;

function setup() {    
    createCanvas(640, 640);        
    restart();
}

function draw() {
    background(48);
    walls();
    noStroke();
    snake.update();
    snake.draw();
    for (let i = 0; i < foodnum; ++i) {
        foods[i].draw();
    }
}

function walls() {
    stroke(255);
    strokeWeight(2);
    line(0, 0, width, 0);
    line(1, 0, 1, height);
    line(height, 0, height, width);
    line(0, height, width, height);
}


class Food {
    constructor() {        
        this.x = floor(random(0, width / grid - 1));
        this.y = floor(random(0, height / grid - 1));
    }   

    draw() {
        fill(180, 100, 100);
        rect(this.x * grid, this.y * grid, grid, grid);
    }
}

function gameover() {
    GameOver = true;
    frameRate(0);
    textSize(32);
    fill(240, 240, 100);
    text('Game Over!', width / 2 - 80, height / 2 - 50);
    text('Press Key to Restart!', 180, height / 2);
}

function restart() {
    GameOver = false; 
    frameRate(10);
    snake = new Snake(10, 10);
    foods = [];
    for (let i = 0; i < foodnum; ++i) {
        foods[i] = new Food();
    }
}

function keyPressed() {
    if (!GameOver) {
        if (snake.sy == 0) {
            if (keyCode == UP_ARROW) {        
                snake.dir(0, -1);
            } else if (keyCode == DOWN_ARROW) {
                snake.dir(0, 1);
            } 
        }
        if (snake.sx == 0) {
            if (keyCode == LEFT_ARROW) {
                snake.dir(-1, 0);
            } else if (keyCode == RIGHT_ARROW) {
                snake.dir(1, 0);
            }
        }
    } else {
        restart();   
    }
}
    

function mousePressed() {
    ++snake.size;
}

class Snake {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.sx = 1;
        this.sy = 0;
        this.size = 20;
        this.body = [];
        for(let i = 0; i < this.size; ++i) {
            this.body[i] = createVector(this.x - i, this.y);
        }
        
    }

    hit() {
        for(let i = this.size - 1; i > 1; --i) {
            let d = dist(this.x, this.y, this.body[i].x, this.body[i].y);
            if (d < 1) {                
                gameover();
            }
        }
        if (this.x < 0 || this.x > width / grid ||
            this.y < 0 || this.y > height / grid) {
                gameover();
        }
    }

    dir(x, y) {
        this.sx = x;
        this.sy = y;
    }

    eat(f) {        
        let d = dist(this.x, this.y, f.x, f.y);
        if (d < 1) {            
            ++this.size;
            for (let i = this.size - 1; i > 0; --i) {
                this.body[i] = this.body[i - 1];
            }     
            this.body[0] = createVector(f.x, f.y);
            return true;            
        } else {
            return false;
        }        
    }

    walk() {
        for (let i = this.size - 1; i > 0; --i) {
            this.body[i] = this.body[i - 1];
        }        
        this.x += this.sx;
        this.y += this.sy;        
        this.body[0] = createVector(this.x, this.y);        
    }

    update() {        
        this.walk();
        
        for (let i = 0; i < foodnum; ++i) {            
            let p = foods[i];
            if(this.eat(p)) {                
                foods[i] = new Food();
            }
        }    

        this.hit();
    }

    draw() {
        fill(255);
        for (let i = 0; i < this.size; ++i) {
            rect(this.body[i].x * grid, this.body[i].y * grid, grid, grid);
        }
    }

}