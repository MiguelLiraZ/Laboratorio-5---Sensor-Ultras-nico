import processing.serial.*;//Libreria Serial
Serial port;//Variable para el Puerto

int n=2; //numero de variables que envía el arduino separadas por coma
float[] data = new float[n];

void setup()
{
  size(700, 700);
  println(Serial.list());//Ver e que puerto esta el arduino
  port = new Serial(this, "COM4", 9600);//Crea e puerto 9600 debe ser igaul en Arduino
  port.bufferUntil('\n');
}

void draw()
{
  if (data[1]==0) {
    background(0);
  }
  
  stroke(0, 255, 0, 10);
  strokeWeight(20);
  
  //data[0], data[1] Contienen la distancia y el ángulo
  
  //Dibuja líneas nuevo marco de referencia
  pushMatrix();
  translate(width/2, 10); //Posición inicial del punto de Escaneo
  rotate(HALF_PI-data[1]*PI/180); 
  line(0, 0, 0, 800);
  stroke(255, 0, 0, 50);
  line(0,data[0]*3,0,800);
  popMatrix();
}

//Función que corre sola cada vez que entra información por el puerto serial
void serialEvent(Serial port) {
  String bufString = port.readString();
  data = float(split(bufString, ','));
}
