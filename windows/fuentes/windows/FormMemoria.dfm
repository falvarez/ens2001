object frmMemoria: TfrmMemoria
  Left = 590
  Top = 176
  Width = 195
  Height = 300
  HorzScrollBar.Visible = False
  VertScrollBar.Tracking = True
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSizeToolWin
  Caption = 'Ens2001-Memoria'
  Color = clBtnFace
  Constraints.MaxWidth = 195
  Constraints.MinHeight = 300
  Constraints.MinWidth = 195
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = Cerrar
  OnDeactivate = MemoriaDeactivate
  OnHide = Ocultar
  OnKeyDown = LeerTecla
  OnPaint = Actualizar
  OnResize = MemoriaResize
  OnShow = Mostrar
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 22
    Top = 3
    Width = 25
    Height = 13
    Caption = 'Zona'
  end
  object Label2: TLabel
    Left = 63
    Top = 3
    Width = 45
    Height = 13
    Caption = 'Dirección'
  end
  object Label3: TLabel
    Left = 126
    Top = 3
    Width = 24
    Height = 13
    Caption = 'Valor'
  end
  object grdMemoria: TStringGrid
    Left = 8
    Top = 16
    Width = 172
    Height = 190
    ColCount = 3
    DefaultColWidth = 50
    DefaultRowHeight = 16
    FixedCols = 0
    RowCount = 65536
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goDrawFocusSelected, goRowSelect]
    ScrollBars = ssVertical
    TabOrder = 0
    OnDblClick = EditarMemoria
    OnKeyDown = LeerTecla
    OnTopLeftChanged = Actualizar
  end
  object btnReiniciar: TButton
    Left = 8
    Top = 216
    Width = 172
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Reiniciar Valores'
    TabOrder = 1
    OnClick = BotonReiniciarClick
  end
  object txtIrA: TEdit
    Left = 8
    Top = 248
    Width = 65
    Height = 21
    Anchors = [akLeft, akRight, akBottom]
    TabOrder = 2
    OnKeyDown = LeerTecla
  end
  object btnIrA: TButton
    Left = 80
    Top = 248
    Width = 100
    Height = 25
    Anchors = [akLeft, akRight, akBottom]
    Caption = 'Ir A Dirección'
    TabOrder = 3
    OnKeyDown = LeerTecla
  end
end
