var pm;


function setup() {
    createCanvas(512, 512);
    noStroke();
    pm = new ParticlesManager(width / 2, 100);
}

function draw() {
    background(48);
    pm.update();
}

class ParticlesManager {
    constructor(x, y) {
        this.position = createVector(x, y);
        this.particles = [];
    }

    update() {
        
        this.particles.push(new Particle(this.position));
        for(let i = this.particles.length - 1; i >= 0; --i) {
  
            let p = this.particles[i];
            p.update();
            p.display();
            if (p.isDead())
                this.particles.splice(i, 1);
        } 
        
    }
}

class Particle {
    constructor(position) {
        this.position = position.copy();
        this.lifetime = 255.0;
        this.acceleration = createVector(0, 0.05); // gravitry
        
        this.velocity = createVector(random(-2.5, 2.5), random(-5, 5)); 
        this.r = random(200, 250);
        this.g = random(120, 150);
        this.b = random(50, 150);
    }

    update() {
        this.lifetime -= 1;
        this.velocity.add(this.acceleration);
        this.position.add(this.velocity);
    }

    display() {
        fill(this.r, this.g, this.b, this.lifetime);
        ellipse(this.position.x, this.position.y, (255 - this.lifetime) / 5);
    }

    isDead() {
        if (this.lifetime < 0) {
            return true;
        } else {
            return false;
        }
    }
}
