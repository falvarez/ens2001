object frmFuente: TfrmFuente
  Left = 310
  Top = 182
  Width = 275
  Height = 300
  HorzScrollBar.Visible = False
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSizeToolWin
  Caption = 'Ens2001-Fuente'
  Color = clBtnFace
  Constraints.MaxWidth = 275
  Constraints.MinHeight = 290
  Constraints.MinWidth = 275
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = Cerrar
  OnDeactivate = FuenteDeactivate
  OnHide = Ocultar
  OnKeyDown = LeerTecla
  OnPaint = Actualizar
  OnResize = FuenteResize
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 47
    Top = 3
    Width = 45
    Height = 13
    Caption = 'Dirección'
  end
  object Label3: TLabel
    Left = 134
    Top = 3
    Width = 52
    Height = 13
    Caption = 'Instrucción'
  end
  object grdFuente: TStringGrid
    Left = 7
    Top = 16
    Width = 250
    Height = 190
    ColCount = 3
    DefaultColWidth = 40
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 65536
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goColSizing, goRowSelect]
    ScrollBars = ssVertical
    TabOrder = 0
    OnDblClick = EditarPuntoRuptura
    OnKeyDown = LeerTecla
    OnTopLeftChanged = Actualizar
  end
  object txtIrA: TEdit
    Left = 8
    Top = 244
    Width = 65
    Height = 21
    Anchors = [akLeft, akRight, akBottom]
    TabOrder = 1
    OnKeyDown = LeerTecla
  end
  object btnIrA: TButton
    Left = 79
    Top = 243
    Width = 178
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Desensamblar A Partir De'
    Default = True
    TabOrder = 2
    OnClick = BotonIrAClick
    OnKeyDown = LeerTecla
  end
  object btnCentrar: TButton
    Left = 8
    Top = 213
    Width = 249
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Desensamblar A Partir de PC'
    TabOrder = 3
    OnClick = BotonCentrarClick
    OnKeyDown = LeerTecla
  end
end
