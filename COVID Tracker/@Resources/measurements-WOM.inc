[Rainmeter]
Update=#UpdateRate#

[Variables]
; Includes the variables/styles used for the skin.
@include1=#@#variables.inc

SiteURL=https://www.worldometers.info/coronavirus/country/#Country#/

[MeasureSiteURL]
Measure=String
String=#ShowGlobal#
IfCondition=(#ShowGlobal# = 1)
IfTrueAction=[!SetVariable SiteURL "https://www.worldometers.info/coronavirus/"][!UpdateMeasureGroup UpdateSite]
IfFalseAction=[!SetVariable SiteURL "https://www.worldometers.info/coronavirus/country/#Country#/"]
IfCondition2=(#ShowGlobal# = 2)
IfTrueAction2=[!WriteKeyValue Variables DisplayText #Country# "#@#variables.inc"]

; ========= Pull info from website ==========

[MCases]
Measure=Plugin
Plugin=WebParser
URL=#SiteURL#
RegExp=(?siU)<span style="color:#aaa">(.*)</span>
UpdateRate=#UpdateRate#
DynamicVariables=1
StringIndex=1

[MDeaths]
Measure=Plugin
Plugin=WebParser
URL=#SiteURL#
RegExp=(?siU)<div class="maincounter-number">.*<span>(.*)</span>
UpdateRate=#UpdateRate#
DynamicVariables=1
StringIndex=1

[MRecovered]
Measure=Plugin
Plugin=WebParser
URL=#SiteURL#
RegExp=(?siU)<div class="maincounter-number" style="color:#8ACA2B ">.*<span>(.*)</span>
UpdateRate=#UpdateRate#
DynamicVariables=1
StringIndex=1