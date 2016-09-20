object FormRegistracija: TFormRegistracija
  Left = 184
  Top = 126
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Registracija'
  ClientHeight = 456
  ClientWidth = 638
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 25
  object l_ime: TLabel
    Left = 144
    Top = 112
    Width = 31
    Height = 25
    Caption = 'Ime'
  end
  object l_prezime: TLabel
    Left = 144
    Top = 152
    Width = 68
    Height = 25
    Caption = 'Prezime'
  end
  object l_username: TLabel
    Left = 144
    Top = 192
    Width = 85
    Height = 25
    Caption = 'Username'
  end
  object l_password: TLabel
    Left = 144
    Top = 232
    Width = 80
    Height = 25
    Caption = 'Password'
  end
  object ed_ime: TEdit
    Left = 264
    Top = 104
    Width = 241
    Height = 33
    TabOrder = 0
  end
  object ed_prezime: TEdit
    Left = 264
    Top = 144
    Width = 241
    Height = 33
    TabOrder = 1
  end
  object ed_username: TEdit
    Left = 264
    Top = 184
    Width = 241
    Height = 33
    TabOrder = 2
  end
  object ed_password: TEdit
    Left = 264
    Top = 224
    Width = 241
    Height = 33
    TabOrder = 3
  end
  object bt_registracija: TButton
    Left = 248
    Top = 280
    Width = 137
    Height = 33
    Caption = 'Registruj se'
    TabOrder = 4
    OnClick = bt_registracijaClick
  end
end
