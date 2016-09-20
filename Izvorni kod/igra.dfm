object FormIgra: TFormIgra
  Left = 229
  Top = 117
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Labirint2013'
  ClientHeight = 505
  ClientWidth = 803
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWhite
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  OnClose = formClose
  OnKeyDown = FormIgraKeyDown
  PixelsPerInch = 96
  TextHeight = 21
  object im_podaci: TImage
    Left = 504
    Top = 0
    Width = 297
    Height = 505
  end
  object Shape1: TShape
    Left = 544
    Top = 104
    Width = 217
    Height = 49
    Brush.Color = clNone
  end
  object im_podloga: TImage
    Left = 0
    Top = 0
    Width = 505
    Height = 505
  end
  object im_igrac: TImage
    Left = 50
    Top = 50
    Width = 17
    Height = 17
  end
  object l_vrijemeTekst: TLabel
    Left = 560
    Top = 120
    Width = 54
    Height = 21
    Caption = 'Vrijeme'
    Color = clNone
    ParentColor = False
  end
  object l_vrijeme: TLabel
    Left = 640
    Top = 118
    Width = 81
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '99'
    Color = clNone
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clAqua
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Shape2: TShape
    Left = 544
    Top = 176
    Width = 217
    Height = 49
    Brush.Color = clNone
  end
  object l_rezultatTekst: TLabel
    Left = 560
    Top = 192
    Width = 56
    Height = 21
    Caption = 'Rezultat'
    Color = clNone
    ParentColor = False
  end
  object l_rezultat: TLabel
    Left = 640
    Top = 190
    Width = 81
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clNone
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clAqua
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Shape3: TShape
    Left = 544
    Top = 248
    Width = 217
    Height = 49
    Brush.Color = clNone
  end
  object l_levelTekst: TLabel
    Left = 560
    Top = 264
    Width = 36
    Height = 21
    Caption = 'Level'
    Color = clNone
    ParentColor = False
  end
  object l_level: TLabel
    Left = 640
    Top = 262
    Width = 81
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = '0'
    Color = clNone
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clAqua
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object im_cilj: TImage
    Left = 408
    Top = 432
    Width = 25
    Height = 25
  end
  object Shape4: TShape
    Left = 544
    Top = 40
    Width = 217
    Height = 33
    Brush.Color = clNavy
  end
  object l_ime: TLabel
    Left = 552
    Top = 44
    Width = 201
    Height = 25
    Alignment = taCenter
    AutoSize = False
    Caption = 'l_ime'
    Color = clNavy
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clSilver
    Font.Height = -19
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object bt_pauza: TButton
    Left = 584
    Top = 320
    Width = 137
    Height = 33
    Caption = 'Pauza'
    TabOrder = 0
    OnClick = bt_pauzaClick
  end
  object ed_nick: TEdit
    Left = 544
    Top = 384
    Width = 217
    Height = 29
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clBlack
    Font.Height = -16
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
  end
  object bt_sacuvaj: TButton
    Left = 584
    Top = 424
    Width = 137
    Height = 33
    Caption = 'Sa'#269'uvaj rezultat'
    TabOrder = 2
    Visible = False
    OnClick = bt_sacuvajClick
  end
  object tm_timer: TTimer
    Enabled = False
    OnTimer = tm_timerOnTimer
    Left = 504
    Top = 16
  end
end
