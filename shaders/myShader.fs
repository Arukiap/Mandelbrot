#version 410 core

/*
 * Fragment Shader - Where the magic happens
 */

in vec4 gl_FragCoord;

varying float vSystemTime;
varying vec2 vSystemResolution;

float maxIterations = 100;

vec2 orbitTrap = vec2(2.0,2.0); //Max length is always 2

// (x+yi)(x+yi) = x^2 + 2xyi - y^2
// imaginary numbers represented by vec2(real,imaginary)
vec2 squareImaginary(vec2 number){
	return vec2(
		pow(number.x,2)-pow(number.y,2),
		2*number.x*number.y
	);
}

float iterateMandebrot(vec2 coord){
	vec2 z = vec2(0,0);
	for(int i=0;i<maxIterations;i++){
		z = squareImaginary(z) + coord;
		orbitTrap = min(orbitTrap,abs(z));
		if(length(z)>2) return i/maxIterations;
	}
	return maxIterations;
}

void main(){	
	vec2 teste = gl_FragCoord.xy/vSystemResolution;
	teste.x = teste.x*4-2;
	teste.y = teste.y*4-2;
	gl_FragColor = vec4(iterateMandebrot(teste));
}