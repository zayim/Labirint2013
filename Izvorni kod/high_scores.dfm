object FormHighScores: TFormHighScores
  Left = 179
  Top = 88
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'High Scores'
  ClientHeight = 571
  ClientWidth = 698
  Color = clBtnFace
  Font.Charset = EASTEUROPE_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Segoe UI'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 21
  object l_bestNick: TLabel
    Left = 176
    Top = 40
    Width = 52
    Height = 37
    Caption = 'Nick'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object l_bestScore: TLabel
    Left = 392
    Top = 40
    Width = 96
    Height = 37
    Caption = 'Rezultat'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object sg_rezultati: TStringGrid
    Left = 128
    Top = 120
    Width = 417
    Height = 409
    ColCount = 3
    DefaultColWidth = 135
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    TabOrder = 0
  end
end
