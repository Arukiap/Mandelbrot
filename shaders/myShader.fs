#version 410 core

/*
 * Fragment Shader - Where the magic happens
 */

in vec4 gl_FragCoord;

varying float vSystemTime;
varying vec2 vSystemResolution;
varying vec3 vMouse;

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

//                                  x    y    z     w
//vec4 coordinateRange represents (Xmin,Xmax,Ymin,Ymax) we want from our screen
vec2 getCoordinatesFromScreen(vec2 fragCoord, vec2 vSystemResolution, vec4 coordinateRange){
	vec2 normalizedCoordinates = gl_FragCoord.xy/vSystemResolution; //From 0 to 1 where pixel is in screen

	float horizontalSize = coordinateRange.y-coordinateRange.x; //Size of horizontal part of screen
	float verticalSize = coordinateRange.w-coordinateRange.z; //Size of vertical part of screen
	
	normalizedCoordinates.x = normalizedCoordinates.x*horizontalSize+coordinateRange.x; //Multiply by size and add initial offset position
	normalizedCoordinates.y = normalizedCoordinates.y*verticalSize+coordinateRange.z;

	return normalizedCoordinates;
}

void main(){	
	vec2 pixelCoordinates = getCoordinatesFromScreen(gl_FragCoord.xy,
													vSystemResolution,
													vec4(-2.0,2.0,-2.0,2.0)*vMouse.z+vec4(vec2(vMouse.x),vec2(-vMouse.y)));
	gl_FragColor = vec4(1.0,1.0,1.0,1.0)*iterateMandebrot(pixelCoordinates);
}