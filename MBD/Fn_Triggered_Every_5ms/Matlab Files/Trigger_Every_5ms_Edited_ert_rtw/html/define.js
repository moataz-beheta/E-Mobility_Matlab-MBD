function CodeDefine() { 
this.def = new Array();
this.def["sample_usage_In1"] = {file: "ert_main_c.html",line:30,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:52,type:"fcn"};
this.def["Trigger_Every_5ms_Edited_M_"] = {file: "Trigger_Every_5ms_Edited_c.html",line:23,type:"var"};
this.def["Trigger_Every_5ms_Edited_M"] = {file: "Trigger_Every_5ms_Edited_c.html",line:24,type:"var"};
this.def["Trigger_Eve_TriggeredSubsystem1"] = {file: "Trigger_Every_5ms_Edited_c.html",line:28,type:"fcn"};
this.def["In1"] = {file: "Trigger_Every_5ms_Edited_c.html",line:47,type:"fcn"};
this.def["Trigger_Every_5ms_Edited_initialize"] = {file: "Trigger_Every_5ms_Edited_c.html",line:58,type:"fcn"};
this.def["Trigger_Every_5ms_Edited_terminate"] = {file: "Trigger_Every_5ms_Edited_c.html",line:67,type:"fcn"};
this.def["RT_MODEL_Trigger_Every_5ms_Ed_T"] = {file: "Trigger_Every_5ms_Edited_types_h.html",line:23,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:50,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:51,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:52,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:53,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:54,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:81,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:86,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:91,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:98,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:105,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:112,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:119,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:126,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:133,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:151,type:"type"};
this.def["DIO_voidSetPinDirection"] = {file: "Dio_program_c.html",line:7,type:"fcn"};
this.def["DIO_voidSetPinValue"] = {file: "Dio_program_c.html",line:70,type:"fcn"};
this.def["DIO_u8GetPinValue"] = {file: "Dio_program_c.html",line:114,type:"fcn"};
this.def["DIO_voidSetPortDirection"] = {file: "Dio_program_c.html",line:147,type:"fcn"};
this.def["DIO_voidSetPortValue"] = {file: "Dio_program_c.html",line:174,type:"fcn"};
this.def["Led_TurnOn"] = {file: "LED_c.html",line:5,type:"fcn"};
this.def["Led_TurnOff"] = {file: "LED_c.html",line:25,type:"fcn"};
this.def["ReadSwitch"] = {file: "Switch_c.html",line:4,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["Trigger_Every_5ms_Edited_c.html"] = "../Trigger_Every_5ms_Edited.c";
	this.html2Root["Trigger_Every_5ms_Edited_c.html"] = "Trigger_Every_5ms_Edited_c.html";
	this.html2SrcPath["Trigger_Every_5ms_Edited_h.html"] = "../Trigger_Every_5ms_Edited.h";
	this.html2Root["Trigger_Every_5ms_Edited_h.html"] = "Trigger_Every_5ms_Edited_h.html";
	this.html2SrcPath["Trigger_Every_5ms_Edited_private_h.html"] = "../Trigger_Every_5ms_Edited_private.h";
	this.html2Root["Trigger_Every_5ms_Edited_private_h.html"] = "Trigger_Every_5ms_Edited_private_h.html";
	this.html2SrcPath["Trigger_Every_5ms_Edited_types_h.html"] = "../Trigger_Every_5ms_Edited_types.h";
	this.html2Root["Trigger_Every_5ms_Edited_types_h.html"] = "Trigger_Every_5ms_Edited_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["Dio_program_c.html"] = "../../Dio_program.c";
	this.html2Root["Dio_program_c.html"] = "Dio_program_c.html";
	this.html2SrcPath["LED_c.html"] = "../../LED.c";
	this.html2Root["LED_c.html"] = "LED_c.html";
	this.html2SrcPath["Switch_c.html"] = "../../Switch.c";
	this.html2Root["Switch_c.html"] = "Switch_c.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","Trigger_Every_5ms_Edited_c.html","Trigger_Every_5ms_Edited_h.html","Trigger_Every_5ms_Edited_private_h.html","Trigger_Every_5ms_Edited_types_h.html","rtwtypes_h.html","Dio_program_c.html","LED_c.html","Switch_c.html"];
