object frmValorRegistro: TfrmValorRegistro
  Left = 240
  Top = 131
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  ClientHeight = 73
  ClientWidth = 112
  Color = clBtnFace
  Constraints.MaxHeight = 100
  Constraints.MaxWidth = 120
  Constraints.MinHeight = 100
  Constraints.MinWidth = 120
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnKeyDown = LeerTecla
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object lblRegistro: TLabel
    Left = 19
    Top = 10
    Width = 16
    Height = 13
    Caption = 'RO'
  end
  object txtRegistro: TEdit
    Left = 48
    Top = 8
    Width = 49
    Height = 21
    TabOrder = 0
    OnKeyDown = LeerTecla
  end
  object btnAceptar: TButton
    Left = 32
    Top = 40
    Width = 49
    Height = 25
    Caption = '&Aceptar'
    Default = True
    TabOrder = 1
    OnClick = BotonAceptarClick
    OnKeyDown = LeerTecla
  end
end
