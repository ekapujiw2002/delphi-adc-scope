unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, CPort, LPControl, SLControlCollection, LPControlDrawLayers,
  SLScope, ExtCtrls, StdCtrls;

type
  TForm1 = class(TForm)
    comportMain: TComPort;
    cmdtpcktMain: TComDataPacket;
    slscpMain: TSLScope;
    tmr1: TTimer;
    lblData: TLabel;
    procedure tmr1Timer(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure cmdtpcktMainPacket(Sender: TObject; const Str: String);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

//get token string

function GetToken(aString: string; SepChar: Char; TokenNum: Byte): string;
var
  Token: string;
  StrLen: Integer;
  Num: Integer;
  EndofToken: Integer;
begin
  StrLen := Length(aString);
  Num := 1;
  EndofToken := StrLen;
  while ((Num <= TokenNum) and (EndofToken <> 0)) do
  begin
    EndofToken := Pos(SepChar, aString);
    if EndofToken <> 0 then
    begin
      Token := Copy(aString, 1, EndofToken - 1);
      Delete(aString, 1, EndofToken);
      Inc(Num);
    end
    else
      Token := aString;
  end;
  if Num >= TokenNum then
    Result := Token
  else
    Result := '';
end;

procedure TForm1.tmr1Timer(Sender: TObject);
begin
  try
  except

  end;
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  try
    cmdtpcktMain.StartString := '#';
    cmdtpcktMain.StopString := #13#10;
    comportMain.Open;
  except

  end;
end;

procedure TForm1.cmdtpcktMainPacket(Sender: TObject; const Str: String);
begin
try
  lblData.Caption:='DATA = '+Str;
   with slscpMain do
   begin
      Channels[0].Data.AddYPoint(StrToFloatDef(GetToken(Str,',',1),0));
      Channels[1].Data.AddYPoint(StrToFloatDef(GetToken(Str,',',2),0));
      Channels[2].Data.AddYPoint(StrToFloatDef(GetToken(Str,',',3),0));
   end;
except

end;  
end;

end.

