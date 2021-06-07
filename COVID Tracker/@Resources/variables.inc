[Rainmeter]
DynamicVariables=1

[Variables]
;==========================
; General settings
;==========================

MenuTreePath=Config\Continents.ini
; Use a menu tree to select the country or state of which to display stats
	; "Config\Continents.ini" = some variables in this file will be updated automatically
	; "-" = all variables in this file will have to be updated manually

OffsetForBottom=1
; If you want to place the skin at the bottom of your screen and have the menus pop up instead of down
	; Skin at top of screen: OffsetForBottom=0
	; Skin at bottom of screen: OffsetForBottom=1

Source=API
; Where to pull the source data from, options are:
	; WOM = WorldOMeter (https://www.worldometers.info)
		; WOM does not have States information so make sure you change #ShowGlobal# to either 0 or 1 else the labels will be wrong
	; API = NovelCOVID-API (https://corona.lmao.ninja/)

Continent=World
; Choose from any of the following continents
	; World
	; Africa	; North America
	; Asia		; Oceania
	; Europe	; South America

Country=US
; For a list of acceptable countries and their correct spelling see the following file:
	; #ROOTCONFIG#\Config\DO NOT USE\Countries.ini

State=Virginia
; Must be a US state and spelled correctly.  Only US states are supported at this time

ShowGlobal=0
; World values = 1
; Individual country values = 0
; Individual US state values = 2
	; The WOM source cannot provide state values, only world or individual countries
; Continent values = 3

DisplayText=US
; Text to display for the descriptions
; This is automatically updated based on the value of #ShowGlobal#

fontName=Montserrat SemiBold
; Font to use for the skin

textSize1=15
; Text size for the counts
textSize2=10
; Text size for the descriptions

colorText=255,255,255
; Text color

colorBackground=0,0,0,100
; Color for the background of dropdown menus
colorBackground2=0,0,0,255

UpdateRate=300
;600 = 10 minutes

[UpdateMenuBackground]
Measure=String
DynamicVariables=1
String=#OffsetForBottom#
IfCondition=(#OffsetForBottom#=1)
IfTrueAction=[!WriteKeyValue Variables "colorBackground2" "0,0,0,255" "#@#variables.inc"]
IfFalseAction=[!WriteKeyValue Variables "colorBackground2" "#colorBackground#" "#@#variables.inc"]
IfConditionMode=1

[UpdateDisplayText]
Measure=String
DynamicVariables=1
String=#ShowGlobal#
IfCondition=(#ShowGlobal# = 1)
IfTrueAction=[!SetVariable DisplayText "World"]
IfCondition2=(#ShowGlobal# = 0)
IfTrueAction2=[!SetVariable DisplayText "#Country#"]
IfCondition3=(#ShowGlobal# = 2)
IfTrueAction3=[!SetVariable DisplayText "#State#"]
IfCondition4=(#ShowGlobal# = 3)
IfTrueAction4=[!SetVariable DisplayText "#Continent#"]
