# Boris Method
## Sample Code
```
/*grab magnetic field at current position*/
B=EvalB(x);

/*get new velocity at n+1*/
v2[0] = v[0] + q/m*B*v[1]*dt;
v2[1] = v[1] - q/m*B*v[0]*dt;

/*update position*/
x2[0] = x[0] + v2[0]*dt;
x2[1] = x[1] + v2[1]*dt;

/*push down*/
v[0]=v2[0];
v[1]=v2[1];
```
## Links
- [Boris Method Article](https://www.particleincell.com/2011/vxb-rotation/)