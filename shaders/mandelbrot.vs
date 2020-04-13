#version 410 core

/*
 * Vertex Shader - Only passes shared values from CPU to the fragment shader. 
 */

attribute vec3 pos;

varying float vSystemTime;
varying vec2 vSystemResolution;
varying vec3 vMouse;

uniform float systemTime;
uniform vec2 systemResolution;
uniform vec3 mouse;

void main(){
    gl_Position = vec4(pos,1.0);
    vSystemTime = systemTime;
    vSystemResolution = systemResolution;
    vMouse = mouse;
}