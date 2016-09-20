object FormGlavna: TFormGlavna
  Left = 193
  Top = 124
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Labirint2013 - by Nadin Zajimovi'#263
  ClientHeight = 461
  ClientWidth = 586
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clNavy
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 21
  object im_pozadina: TImage
    Left = 1
    Top = 0
    Width = 584
    Height = 461
  end
  object l_imePrezime: TLabel
    Left = 24
    Top = 184
    Width = 6
    Height = 30
    Color = clBlack
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -21
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Visible = False
    OnClick = l_imePrezimeClick
    OnMouseEnter = l_imePrezimeMouseEnter
    OnMouseLeave = l_imePrezimeMouseLeave
  end
  object bt_novaIgra: TButton
    Left = 224
    Top = 192
    Width = 137
    Height = 33
    Caption = 'Nova igra'
    TabOrder = 0
    OnClick = bt_novaIgraClick
  end
  object bt_prijava: TButton
    Left = 224
    Top = 232
    Width = 137
    Height = 33
    Caption = 'Prijavi se'
    TabOrder = 1
    OnClick = bt_prijavaClick
  end
  object bt_registracija: TButton
    Left = 224
    Top = 272
    Width = 137
    Height = 33
    Caption = 'Registracija'
    TabOrder = 2
    OnClick = bt_registracijaClick
  end
  object bt_pomoc: TButton
    Left = 224
    Top = 312
    Width = 137
    Height = 33
    Caption = 'Pomo'#263
    TabOrder = 3
    OnClick = bt_pomocClick
  end
  object bt_kraj: TButton
    Left = 224
    Top = 352
    Width = 137
    Height = 33
    Caption = 'Kraj'
    TabOrder = 4
    OnClick = bt_krajClick
  end
  object bt_highScores: TButton
    Left = 224
    Top = 408
    Width = 137
    Height = 33
    Caption = 'High Scores'
    TabOrder = 5
    OnClick = bt_highScoresClick
  end
end
