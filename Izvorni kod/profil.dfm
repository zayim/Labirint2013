object FormProfil: TFormProfil
  Left = 196
  Top = 123
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Profil'
  ClientHeight = 463
  ClientWidth = 555
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 20
  object Label1: TLabel
    Left = 48
    Top = 30
    Width = 25
    Height = 20
    Caption = 'Ime'
  end
  object Label2: TLabel
    Left = 48
    Top = 70
    Width = 53
    Height = 20
    Caption = 'Prezime'
  end
  object Label3: TLabel
    Left = 48
    Top = 108
    Width = 66
    Height = 20
    Caption = 'Username'
  end
  object Label4: TLabel
    Left = 48
    Top = 148
    Width = 62
    Height = 20
    Caption = 'Password'
  end
  object Label5: TLabel
    Left = 200
    Top = 200
    Width = 77
    Height = 20
    Caption = 'Broj partija:'
  end
  object l_broj: TLabel
    Left = 288
    Top = 200
    Width = 37
    Height = 20
    Caption = 'l_broj'
  end
  object ed_ime: TEdit
    Left = 144
    Top = 24
    Width = 169
    Height = 28
    ReadOnly = True
    TabOrder = 0
    Text = 'ed_ime'
  end
  object ed_prezime: TEdit
    Left = 144
    Top = 64
    Width = 169
    Height = 28
    ReadOnly = True
    TabOrder = 1
    Text = 'ed_prezime'
  end
  object ed_username: TEdit
    Left = 144
    Top = 104
    Width = 169
    Height = 28
    ReadOnly = True
    TabOrder = 2
    Text = 'ed_username'
  end
  object ed_password: TEdit
    Left = 144
    Top = 144
    Width = 169
    Height = 28
    ReadOnly = True
    TabOrder = 3
    Text = 'ed_password'
  end
  object sg_rezultati: TStringGrid
    Left = 72
    Top = 240
    Width = 417
    Height = 137
    ColCount = 2
    DefaultColWidth = 200
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 4
  end
end
