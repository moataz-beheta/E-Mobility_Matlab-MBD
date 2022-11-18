function Turn_On_Yellow_Light(Yellow_Light_Auto_Timer)
    global radius;
    global th;
    global arduinoObject;
    global Red_Light_Pin;
    global Yellow_Light_Pin;
    global Green_Light_Pin;
    
    writeDigitalPin(arduinoObject,Red_Light_Pin,0); 
    writeDigitalPin(arduinoObject,Yellow_Light_Pin,1); 
    writeDigitalPin(arduinoObject,Green_Light_Pin,0);
    
    Light_Yellow_RGB= 'y';

    % Red circle %
    Origin_x= 10;
    Origin_y= 20;
    x = radius * cos(th) + Origin_x;
    y = radius * sin(th) + Origin_y;
    fill(x,y,Light_Yellow_RGB);
    
end