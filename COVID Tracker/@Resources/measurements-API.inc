[Rainmeter]
Update=#UpdateRate#
DynamicVariables=1

[Metadata]
Name=COVID 19 Tracker
Author=Mrunal Sonawane
Information=Get Basic COVID 19 Information For A Country
License=Attribution-ShareAlike 4.0 International
Version=1.2.0.0

[Variables]
@include=#@#variables.inc
ShowFlag=1

API=https://corona.lmao.ninja/v2/
APIG=#API#all
APIC=[#API]countries/#Country#
APIS=[#API]states/#State#


[GetJSON]
Measure=Plugin
Plugin=WebParser.dll
DynamicVariables=1
UpdateRate=#UpdateRate#
IfCondition=(#ShowGlobal# = 1)
IfTrueAction=[!SetOption GetJSON Url #*APIG*#][!PauseMeasure "Flag"][!PauseMeasure "MeasureWebsite"]
IfCondition2=(#ShowGlobal# = 0)
IfTrueAction2=[!SetOption GetJSON Url #*APIC*#][!UnpauseMeasure "Flag"][!UnpauseMeasure "MeasureWebsite"]
IfCondition3=(#ShowGlobal# = 2)
IfTrueAction3=[!SetOption GetJSON Url #*APIS*#][!PauseMeasure "Flag"][!PauseMeasure "MeasureWebsite"]

RegExp=(?siU)^(.*)$
FinishAction=[!SetOption MCases Disabled 0][!SetOption MDeaths Disabled 0][!SetOption MRecovered Disabled 0][!SetOption MTodayCases Disabled 0][!SetOption MTodayDeaths Disabled 0][!SetOption Flag Disabled 0]


[Flag]
Measure=Plugin
Plugin=JsonParser.dll
DynamicVariables=1
Source=[GetJSON]
Query="countryInfo.flag"

[MeasureWebsite]
Measure=Plugin
Plugin=WebParser.dll
DynamicVariables=1
UpdateRate=5
Url=[&Flag]
Download=#ShowFlag#
DownloadFile=flag.png
FinishAction=!RainmeterRedraw

[MCases]
Measure=Plugin
Plugin=JsonParser.dll
Source=[GetJSON]
Query="cases"
Disabled=1
RegExpSubstitute=1
Substitute="\d{1,3}(?=(\d{3})+$)":"\0,"

[MDeaths]
Measure=Plugin
Plugin=JsonParser.dll
Source=[GetJSON]
Query="deaths"
Disabled=1
RegExpSubstitute=1
Substitute="\d{1,3}(?=(\d{3})+$)":"\0,"

[EnableDisableMRecovered]
Measure=String
String=#ShowGlobal#
DynamicVariables=1
IfCondition=(#ShowGlobal# = 2)
IfTrueAction=[!PauseMeasure MRecovered]
IfFalseAction[!UnpauseMeasure MRecovered]

[MRecovered]
Measure=Plugin
Plugin=JsonParser.dll
Source=[GetJSON]
Query="recovered"
Disabled=1
RegExpSubstitute=1
Substitute="\d{1,3}(?=(\d{3})+$)":"\0,"

[MTodayCases]
Measure=Plugin
Plugin=JsonParser.dll
Source=[GetJSON]
Query="todayCases"
Disabled=1
RegExpSubstitute=1
Substitute="\d{1,3}(?=(\d{3})+$)":"\0,"

[MTodayDeaths]
Measure=Plugin
Plugin=JsonParser.dll
Source=[GetJSON]
Query="todayDeaths"
Disabled=1
RegExpSubstitute=1
Substitute="\d{1,3}(?=(\d{3})+$)":"\0,"
