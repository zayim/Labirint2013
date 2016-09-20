object FormPrijava: TFormPrijava
  Left = 199
  Top = 126
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Prijava'
  ClientHeight = 399
  ClientWidth = 594
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 25
  object l_username: TLabel
    Left = 128
    Top = 112
    Width = 85
    Height = 25
    Caption = 'Username'
  end
  object l_password: TLabel
    Left = 128
    Top = 160
    Width = 80
    Height = 25
    Caption = 'Password'
  end
  object ed_username: TEdit
    Left = 240
    Top = 112
    Width = 217
    Height = 33
    TabOrder = 0
  end
  object ed_password: TEdit
    Left = 240
    Top = 160
    Width = 217
    Height = 33
    TabOrder = 1
  end
  object bt_prijava: TButton
    Left = 216
    Top = 232
    Width = 161
    Height = 41
    Caption = 'Prijavi se'
    TabOrder = 2
    OnClick = bt_prijavaClick
  end
end
