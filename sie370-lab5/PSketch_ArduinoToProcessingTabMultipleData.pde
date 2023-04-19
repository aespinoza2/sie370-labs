import processing.serial.*;

Serial mySerial;         // Serial Object
String dataReceived;     // Data received from the serial port
PrintWriter outputFile;  // Text file for the output data

void setup()
{
  // Open your serial port (where you are exchanging the data with Arduino)
  String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  // A handy line to see the list is:
  //println(Serial.list());
  mySerial = new Serial(this, portName, 9600);
  outputFile = createWriter( "outputdata.txt" );

}

void draw()
{
  // check for serial input
  if (mySerial.available() > 0 ) {
    // read a line of input
    dataReceived = mySerial.readStringUntil('\t');
    // bypass nulls
    if ( dataReceived != null ) {
      // write the line to the output file
      outputFile.println(dataReceived);
      println(dataReceived); 
    }
  } 
}

void keyPressed() {
    outputFile.flush();  // Writes the remaining data to the file
    outputFile.close();  // Finishes the file
    exit();  // Stops the program
}
