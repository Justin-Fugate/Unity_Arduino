using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class ArduinoCom : MonoBehaviour {

    public Light lightObject;       //Light to toggle on and Off
    //public string portName;
    //public int baudRate = 9600;

    SerialPort stream = new SerialPort("COM3", 9600);       //PortName, speed

    private void Start()
    {
        //Initialize the name of the port according to the script input
        //sp = new SerialPort(portName, baudRate);
        stream.Open();      //Open the port
        stream.ReadTimeout = 1;  //Make sure input detection doesn't hang 
    }

    void Update()
    {
        //If the Port is open, test to see if there's input we can work with
        if (stream.IsOpen)
        {
            try
            {
                ManipulateLight(stream.ReadByte());
                print(stream.ReadByte());
            }
            catch (System.Exception)
            {
                //Attempt Failed
                //Debug.Log("ReadByte failed!");
            }
        }
        else
        {
            Debug.Log("Port is not open!");
        }
    }

    void ManipulateLight(int ardValue)
    {
        //If the value is between 0-8, and the Light Object is active
        if(ardValue >= 0 && ardValue <= 8)
        {

            //Set the light intensity to be equal to our Arduino written value
            lightObject.intensity = ardValue;
            Debug.Log(ardValue);
        }
        //If the value is 9
        if(ardValue == 9)
        {
            //Turn Light Off
            lightObject.enabled = false;
            Debug.Log(ardValue);
        }
        //If the value is 10
        if(ardValue == 10)
        {
            //Turn Light On
            lightObject.enabled = true;
            Debug.Log(ardValue);
        }
    }

    //Call this Function from a button
    public void LEDOn()
    {
        stream.Write("A");      //Send A Value to Arduino to handle
    }

    //Call this Function fromm a button
    public void LEDOff()
    {
        stream.Write("B");      //Send B Value to Arduino to handle
    }
}
