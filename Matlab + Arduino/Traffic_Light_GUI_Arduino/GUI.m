%% By: Eng. Moataz Beheta
function varargout = GUI(varargin)

% GUI MATLAB code for GUI.fig
%      GUI, by itself, creates a new GUI or raises the existing
%      singleton*.
%
%      H = GUI returns the handle to a new GUI or the handle to
%      the existing singleton*.
%
%      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI.M with the given input arguments.
%
%      GUI('Property','Value',...) creates a new GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before GUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to GUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help GUI

% Last Modified by GUIDE v2.5 02-Nov-2022 23:37:19

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before GUI is made visible.

function GUI_OpeningFcn(hObject, eventdata, handles, varargin)

global Timer;
global radius;
global th;
global arduinoObject
global Red_Light_Pin;
global Yellow_Light_Pin;
global Green_Light_Pin;
global Red_Light_Auto_Timer;
global Yellow_Light_Auto_Timer;
global Green_Light_Auto_Timer;
global Mode;
Red_Light_Pin = 'D11';
Yellow_Light_Pin = 'D10';
Green_Light_Pin = 'D9';

delete(instrfind({'Port'},{'COM6'}))
delete(instrfind({'Port'},{'DEMO'}))
arduinoObject=arduino('COM6','Uno');
configurePin(arduinoObject,Red_Light_Pin,'DigitalOutput');
configurePin(arduinoObject,Yellow_Light_Pin,'DigitalOutput');
configurePin(arduinoObject,Green_Light_Pin,'DigitalOutput');

radius = 2;
th = 0:pi/100:pi*2;
Red_Light_Auto_Timer=3;
Yellow_Light_Auto_Timer=2;
Green_Light_Auto_Timer=4;
Timer = 0;
Mode = 0;

set(handles.Show_Current_Red_Timer_Value, 'String', Red_Light_Auto_Timer);
set(handles.Show_Current_Yellow_Timer_Value, 'String', Yellow_Light_Auto_Timer);
set(handles.Show_Current_Green_Timer_Value, 'String', Green_Light_Auto_Timer);



Traffic_Light_Design();
Turn_Off_All_Lights();
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to GUI (see VARARGIN)

% Choose default command line output for GUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes GUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = GUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in Mode.
function Mode_Callback(hObject, eventdata, handles)
global Timer;
global Mode;
global Red_Light_Auto_Timer;
global Yellow_Light_Auto_Timer;
global Green_Light_Auto_Timer;


axes(handles.Plot);
a= get(handles.Mode,'value');
if a==1 %Automatic Mode
    set(handles.Current_Mode, 'String', 'Automatic');
    Mode = 1;

    while (Mode == 1)
        %Red Light ON
        Turn_Off_All_Lights();
        Turn_On_Red_Light();
        Timer = Red_Light_Auto_Timer;


        while(Timer>=0 && Mode == 1)
            set(handles.Disp_Timer, 'String', Timer);
            pause(1);
            Timer = Timer-1;
        end
        
        %Yellow Light ON
        Turn_Off_All_Lights();
        Turn_On_Yellow_Light();
        Timer = Yellow_Light_Auto_Timer;
        
        while(Timer>=0 && Mode == 1)
            set(handles.Disp_Timer, 'String', Timer);
            pause(1);
            Timer = Timer-1;
        end
        
        %Green Light ON
        Turn_Off_All_Lights();
        Turn_On_Green_Light();
        Timer = Green_Light_Auto_Timer;

        while(Timer>=0 && Mode == 1)
            
            set(handles.Disp_Timer, 'String', Timer);
            pause(1);
            Timer = Timer-1;
        end
    end
    
    else  %Manual Mode 
        Mode = 2;
        Turn_Off_All_Lights();
        set(handles.Current_Mode, 'String', 'Manual');
        set(handles.Disp_Timer, 'String', 'Manual Controlled');
        
        
end
% hObject    handle to Mode (see GCBO)
% eventdata  reserv ed - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Mode


% --- Executes on button press in Red_Button.
function Red_Button_Callback(hObject, eventdata, handles)
global Mode;
if (Mode == 2)
    Turn_Off_All_Lights();
    Turn_On_Red_Light();
end
% hObject    handle to Red_Button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --- Executes on button press in Yellow_Button.
function Yellow_Button_Callback(hObject, eventdata, handles)
global Mode;
if (Mode == 2)
    Turn_Off_All_Lights();
    Turn_On_Yellow_Light();
end
% hObject    handle to Yellow_Button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Green_Button.
function Green_Button_Callback(hObject, eventdata, handles)
global Mode;
if (Mode == 2)
    Turn_Off_All_Lights();
    Turn_On_Green_Light();
end
% hObject    handle to Green_Button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Turn_OFF_ALL_Button.
function Turn_OFF_ALL_Button_Callback(hObject, eventdata, handles)
global Mode;
if (Mode == 2)
    Turn_Off_All_Lights();
end
% hObject    handle to Turn_OFF_ALL_Button (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function Red_Timer_Value_Callback(hObject, eventdata, handles)
% hObject    handle to Red_Timer_Value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Red_Timer_Value as text
%        str2double(get(hObject,'String')) returns contents of Red_Timer_Value as a double


% --- Executes during object creation, after setting all properties.
function Red_Timer_Value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Red_Timer_Value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Set_Red.
function Set_Red_Callback(hObject, eventdata, handles)
global Red_Light_Auto_Timer;
Red_Light_Auto_Timer = str2double(get(handles.Red_Timer_Value,'String'));
set(handles.Show_Current_Red_Timer_Value, 'String', Red_Light_Auto_Timer);
% hObject    handle to Set_Red (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function Yellow_Timer_Value_Callback(hObject, eventdata, handles)

% hObject    handle to Yellow_Timer_Value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Yellow_Timer_Value as text
%        str2double(get(hObject,'String')) returns contents of Yellow_Timer_Value as a double


% --- Executes during object creation, after setting all properties.
function Yellow_Timer_Value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Yellow_Timer_Value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Set_Yellow.
function Set_Yellow_Callback(hObject, eventdata, handles)
global Yellow_Light_Auto_Timer;
Yellow_Light_Auto_Timer = str2double(get(handles.Yellow_Timer_Value,'String'));
set(handles.Show_Current_Yellow_Timer_Value, 'String', Yellow_Light_Auto_Timer);
% hObject    handle to Set_Yellow (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function Green_Timer_Value_Callback(hObject, eventdata, handles)
% hObject    handle to Green_Timer_Value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Green_Timer_Value as text
%        str2double(get(hObject,'String')) returns contents of Green_Timer_Value as a double


% --- Executes during object creation, after setting all properties.
function Green_Timer_Value_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Green_Timer_Value (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Set_Green.
function Set_Green_Callback(hObject, eventdata, handles)
global Green_Light_Auto_Timer;
Green_Light_Auto_Timer = str2double(get(handles.Green_Timer_Value,'String'));
set(handles.Show_Current_Green_Timer_Value, 'String', Green_Light_Auto_Timer);

% hObject    handle to Set_Green (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
