object Form1: TForm1
  Left = 384
  Top = 153
  Width = 1085
  Height = 696
  BiDiMode = bdLeftToRight
  Caption = #1048#1052' ENGINE KAMAZ ('#1042#1077#1088#1089#1080#1103' 01)'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  ParentBiDiMode = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 800
    Top = 16
    Width = 193
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1080' '#1087#1088#1080' '#1088#1072#1073#1086#1090#1077' '#1087#1088#1086#1075#1088#1072#1084#1084#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 440
    Top = 136
    Width = 112
    Height = 13
    Caption = #1055#1088#1080#1085#1103#1090#1099#1077' '#1076#1072#1085#1085#1099#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 448
    Top = 16
    Width = 127
    Height = 13
    Caption = #1055#1077#1088#1077#1076#1072#1085#1085#1099#1077' '#1076#1072#1085#1085#1099#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LCOMPORT: TLabel
    Left = 338
    Top = 20
    Width = 66
    Height = 13
    Caption = #1053#1086#1084#1077#1088' '#1087#1086#1088#1090#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 643
    Width = 1077
    Height = 19
    Panels = <
      item
        Width = 500
      end
      item
        Width = 150
      end
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object MError: TMemo
    Left = 800
    Top = 32
    Width = 241
    Height = 73
    ScrollBars = ssVertical
    TabOrder = 1
    Visible = False
  end
  object M_IN_DATA: TMemo
    Left = 440
    Top = 152
    Width = 601
    Height = 81
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object BStart: TButton
    Left = 336
    Top = 168
    Width = 75
    Height = 25
    Caption = #1057#1090#1072#1088#1090
    TabOrder = 3
    OnClick = BStartClick
  end
  object BExit: TButton
    Left = 336
    Top = 200
    Width = 75
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 4
    OnClick = BExitClick
  end
  object M_OUT_DATA: TMemo
    Left = 440
    Top = 32
    Width = 337
    Height = 89
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object COMPORT: TComboBox
    Left = 328
    Top = 36
    Width = 97
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 6
    Items.Strings = (
      'COM1'
      'COM2'
      'COM3'
      'COM4'
      'COM5'
      'COM6')
  end
  object PCZAPRSVU: TPageControl
    Left = 8
    Top = 8
    Width = 297
    Height = 225
    ActivePage = ZAPRSVU
    TabIndex = 0
    TabOrder = 7
    object ZAPRSVU: TTabSheet
      Caption = #1047#1072#1087#1088#1086#1089' '#1042#1059
      object LPower1: TLabel
        Left = 12
        Top = 159
        Width = 147
        Height = 13
        Caption = #1059#1089#1090#1072#1074#1082#1072' '#1087#1086' '#1085#1072#1087#1088#1103#1078#1077#1085#1080#1102
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LSAVE: TLabel
        Left = 245
        Top = 148
        Width = 37
        Height = 13
        Caption = #1047#1072#1087#1080#1089#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clRed
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object LPower2: TLabel
        Left = 16
        Top = 175
        Width = 105
        Height = 13
        Caption = #1074' '#1087#1088#1086#1084#1082#1086#1085#1090#1091#1088#1077', '#1042
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LSUE: TLabel
        Left = 12
        Top = 7
        Width = 80
        Height = 13
        Caption = #1050#1086#1084#1072#1085#1076#1099' '#1042#1059':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object UpDown1: TUpDown
        Left = 225
        Top = 163
        Width = 16
        Height = 24
        Associate = E_UST_POWER
        ArrowKeys = False
        Min = 0
        Max = 990
        Position = 540
        TabOrder = 0
        Thousands = False
        Wrap = False
      end
      object CheckListBoxChanel1: TCheckListBox
        Left = 8
        Top = 24
        Width = 209
        Height = 113
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemHeight = 13
        Items.Strings = (
          '7'#1088' - '#1056#1077#1079#1077#1088#1074
          '6'#1088' - '#1056#1077#1079#1077#1088#1074
          '5'#1088' - '#1056#1077#1079#1077#1088#1074
          '4'#1088' - '#1056#1077#1079#1077#1088#1074
          '3'#1088' - '#1057#1073#1088#1086#1089' '#1072#1074#1072#1088#1080#1080
          '2'#1088' - '#1047#1072#1088#1103#1076' '#1040#1050#1041
          '1'#1088' - '#1056#1072#1073#1086#1090#1072' '#1086#1090' '#1040#1050#1041
          '0'#1088' - '#1056#1072#1073#1086#1090#1072' '#1086#1090' '#1089#1077#1090#1080' 380 '#1042)
        ParentFont = False
        TabOrder = 1
      end
      object E_UST_POWER: TEdit
        Left = 168
        Top = 163
        Width = 57
        Height = 24
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        MaxLength = 3
        ParentFont = False
        TabOrder = 2
        Text = '540'
        OnChange = E_UST_POWERChange
        OnKeyPress = E_UST_POWERKeyPress
      end
      object CBSAVE: TCheckBox
        Left = 257
        Top = 168
        Width = 17
        Height = 17
        TabOrder = 3
      end
    end
  end
  object PCOTVBS: TPageControl
    Left = 8
    Top = 240
    Width = 1065
    Height = 401
    ActivePage = OTVBS
    TabIndex = 0
    TabOrder = 8
    object OTVBS: TTabSheet
      Caption = #1054#1090#1074#1077#1090' '#1050#1055#1057#1053
      object LD_BSPS0: TLabel
        Left = 64
        Top = 288
        Width = 239
        Height = 13
        Caption = #1063#1072#1089#1090#1086#1090#1072' '#1074#1088#1072#1097'. '#1088#1086#1090#1086#1088#1072' '#1043#1055#1063'-200, '#1086#1073'/'#1084#1080#1085
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LD_BSPS4: TLabel
        Left = 368
        Top = 288
        Width = 246
        Height = 13
        Caption = #1044#1077#1081#1089#1090#1074'. '#1079#1085#1072#1095'. '#1090#1086#1082#1072' '#1092#1072#1079#1099' '#1040' ('#1080#1085#1074#1077#1088#1090#1086#1088'), '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LD_BSPS5: TLabel
        Left = 368
        Top = 316
        Width = 246
        Height = 13
        Caption = #1044#1077#1081#1089#1090#1074'. '#1079#1085#1072#1095'. '#1090#1086#1082#1072' '#1092#1072#1079#1099' B ('#1080#1085#1074#1077#1088#1090#1086#1088'), '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LD_BSPS2: TLabel
        Left = 64
        Top = 316
        Width = 194
        Height = 13
        Caption = #1052#1086#1097#1085#1086#1089#1090#1100' '#1085#1072' '#1074#1072#1083#1091' '#1043#1055#1063'-200, '#1082#1042#1090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LD_BSPS6: TLabel
        Left = 368
        Top = 344
        Width = 246
        Height = 13
        Caption = #1044#1077#1081#1089#1090#1074'. '#1079#1085#1072#1095'. '#1090#1086#1082#1072' '#1092#1072#1079#1099' C ('#1080#1085#1074#1077#1088#1090#1086#1088'), '#1040
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LD_BSPS7: TLabel
        Left = 64
        Top = 344
        Width = 171
        Height = 13
        Caption = #1063#1072#1089#1090#1086#1090#1072' '#1090#1086#1082#1072' '#1048#1085#1074#1077#1088#1090#1086#1088#1072', '#1043#1094
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object LabelDisableCommunication: TLabel
        Left = 962
        Top = 352
        Width = 94
        Height = 13
        Caption = #1053#1077#1090' '#1089#1074#1103#1079#1080' '#1089' '#1050#1055#1057#1053
      end
      object SHNETSV: TShape
        Left = 938
        Top = 350
        Width = 17
        Height = 17
        Pen.Color = clGray
        Pen.Width = 2
        Shape = stEllipse
      end
      object GBD_BSPS10: TGroupBox
        Left = 520
        Top = 12
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1055#1057'-'#1057#1043' ('#1080#1085#1074#1077#1088#1090#1086#1088')'
        TabOrder = 0
        object D_BSPS10: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1040#1074#1072#1088#1080#1103' '#1074' '#1085#1072#1075#1088#1091#1079#1082#1077' '#1055#1063'-'#1057#1043
            '6'#1088' - '#1055#1077#1088#1077#1075#1088#1091#1079#1082#1072' '#1087#1086' '#1090#1086#1082#1091' '#1055#1063'-'#1057#1043
            '5'#1088' - '#1047#1072#1097#1080#1090#1072' '#1087#1086' '#1090#1077#1084#1087#1077#1088'. '#1055#1063'-'#1057#1043
            '4'#1088' - '#1047#1072#1097#1080#1090#1072' '#1087#1086' I '#1089#1080#1083'. '#1089#1073#1086#1088#1082#1080' '#1055#1063'-'#1057#1043
            '3'#1088' - '#1055#1086#1074#1099#1096'. U'#1074#1093' '#1055#1063'-'#1057#1043
            '2'#1088' - '#1055#1086#1085#1080#1078'. U'#1074#1093' '#1055#1063'-'#1057#1043
            '1'#1088' - '#1043#1086#1090#1086#1074#1085#1086#1089#1090#1100' '#1055#1063'-'#1057#1043
            '0'#1088' - '#1043#1086#1090#1086#1074' '#1082' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1102' '#1082' '#1089#1077#1090#1080)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GBD_BSPS8: TGroupBox
        Left = 8
        Top = 12
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1055#1063'-'#1057#1043' ('#1074#1099#1087#1088#1103#1084#1080#1090#1077#1083#1100')'
        TabOrder = 1
        object D_BSPS8: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1040#1074#1072#1088#1080#1103' '#1074' '#1085#1072#1075#1088#1091#1079#1082#1077' '#1055#1063'-'#1057#1043' '
            '6'#1088' - '#1055#1077#1088#1077#1075#1088#1091#1079#1082#1072' '#1087#1086' '#1090#1086#1082#1091' '#1055#1063'-'#1057#1043
            '5'#1088' - '#1047#1072#1097#1080#1090#1072' '#1087#1086' '#1090#1077#1084#1087#1077#1088'. '#1055#1063'-'#1057#1043
            '4'#1088' - '#1047#1072#1097#1080#1090#1072' '#1087#1086' I '#1089#1080#1083'. '#1089#1073#1086#1088#1082#1080' '#1055#1063'-'#1057#1043
            '3'#1088' - '#1055#1086#1074#1099#1096'. U'#1074#1093' '#1055#1063'-'#1057#1043
            '2'#1088' - '#1055#1086#1085#1080#1078'. U'#1074#1093' '#1055#1063'-'#1057#1043
            '1'#1088' - '#1043#1086#1090#1086#1074#1085#1086#1089#1090#1100' '#1055#1063'-'#1057#1043
            '0'#1088' - '#1054#1096#1080#1073#1082#1072' '#1089#1086#1089#1090#1086#1103#1085#1080#1103' '#1044#1061)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GBD_BSPS9: TGroupBox
        Left = 264
        Top = 12
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1043#1055#1063'-200 ('#1074#1099#1087#1088#1103#1084#1080#1090#1077#1083#1100')'
        TabOrder = 2
        object D_BSPS9: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1056#1077#1078#1080#1084' '#1088#1072#1073#1086#1090#1099' '#171#1075#1077#1085#1077#1088#1072#1090#1086#1088#187
            '6'#1088' - '#1057#1082#1086#1088#1086#1089#1090#1100' '#1074#1099#1096#1077' '#1085#1086#1088#1084#1099
            '5'#1088' - '#1047#1072#1097#1080#1090#1072' '#1087#1086' '#1090#1077#1084#1087#1077#1088'. '#1043#1055#1063'-200'
            '4'#1088' - f '#1074#1088#1072#1097'. '#1088#1086#1090#1086#1088#1072' '#1087#1088#1080' '#1085#1080#1078#1077' '#1085#1086#1088#1084#1099
            '3'#1088' - '#1056#1077#1079#1077#1088#1074
            '2'#1088' - '#1056#1077#1079#1077#1088#1074
            '1'#1088' - '#1056#1077#1079#1077#1088#1074
            '0'#1088' - '#1056#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GBD_BSPS13: TGroupBox
        Left = 264
        Top = 148
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1057#1059' '#1052#1072#1082#1077#1090#1072
        TabOrder = 3
        object D_BSPS13: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1040#1074#1072#1088#1080#1103' '#1057#1059' '#1052#1072#1082#1077#1090#1072
            '6'#1088' - '#1043#1086#1090#1086#1074#1085#1086#1089#1090#1100' '#1072#1074#1090#1086#1085#1086#1084#1085#1086#1081' '#1088#1077#1078#1080#1084
            '5'#1088' - '#1043#1086#1090#1086#1074#1085#1086#1089#1090#1100' '#1089#1077#1090#1077#1074#1086#1081' '#1088#1077#1078#1080#1084
            '4'#1088' - '#1056#1077#1079#1077#1088#1074
            '3'#1088' - '#1056#1077#1079#1077#1088#1074
            '2'#1088' - '#1056#1077#1079#1077#1088#1074
            '1'#1088' - '#1056#1077#1079#1077#1088#1074
            '0'#1088' - '#1056#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GBD_BSPS11: TGroupBox
        Left = 776
        Top = 12
        Width = 273
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1055#1057'-'#1057#1043' ('#1080#1085#1074#1077#1088#1090#1086#1088') (2)'
        TabOrder = 4
        object D_BSPS11: TCheckListBox
          Left = 8
          Top = 16
          Width = 258
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1053#1077#1090' '#1089#1074#1103#1079#1080' '#1089' '#1080#1079#1084#1077#1088'. '#1085#1072#1087#1088'. ('#1050#1048' 2 (2))'
            '6'#1088' - '#1056#1077#1079#1077#1088#1074
            '5'#1088' - '#1056#1077#1079#1077#1088#1074
            '4'#1088' - '#1056#1077#1079#1077#1088#1074
            '3'#1088' - '#1056#1077#1079#1077#1088#1074
            '2'#1088' - '#1056#1077#1079#1077#1088#1074
            '1'#1088' - '#1056#1077#1079#1077#1088#1074
            '0'#1088' - '#1056#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GBD_BSPS12: TGroupBox
        Left = 8
        Top = 148
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1057#1074#1103#1079#1080' '#1089' '#1072#1073#1086#1085#1077#1085#1090#1072#1084#1080' '#1057#1059
        TabOrder = 5
        object D_BSPS12: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1053#1077#1090' '#1089#1074#1103#1079#1080' '#1041#1059' '#1089' '#1055#1063'-'#1057#1043' ('#1074#1099#1087#1088'.)'
            '6'#1088' - '#1053#1077#1090' '#1089#1074#1103#1079#1080' '#1041#1059' '#1089' '#1055#1063'-'#1057#1043' ('#1080#1085#1074'.)'
            '5'#1088' - '#1053#1077#1090' '#1089#1074#1103#1079#1080' '#1041#1059' '#1089' '#1050#1048'2 (1)'
            '4'#1088' - '#1053#1077#1090' '#1089#1074#1103#1079#1080' '#1041#1059' '#1089' '#1041#1059#1050
            '3'#1088' - '#1053#1077#1090' '#1089#1074#1103#1079#1080' '#1041#1059' '#1089' '#1041#1042#1057
            '2'#1088' - '#1056#1077#1079#1077#1088#1074
            '1'#1088' - '#1056#1077#1079#1077#1088#1074
            '0'#1088' - '#1056#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
      object ED_BSPS0: TEdit
        Left = 16
        Top = 284
        Width = 41
        Height = 21
        TabOrder = 6
        Text = '0'
      end
      object ED_BSPS4: TEdit
        Left = 320
        Top = 284
        Width = 41
        Height = 21
        TabOrder = 7
        Text = '0'
      end
      object ED_BSPS5: TEdit
        Left = 320
        Top = 312
        Width = 41
        Height = 21
        TabOrder = 8
        Text = '0'
      end
      object ED_BSPS2: TEdit
        Left = 16
        Top = 312
        Width = 41
        Height = 21
        TabOrder = 9
        Text = '0'
      end
      object ED_BSPS6: TEdit
        Left = 320
        Top = 340
        Width = 41
        Height = 21
        TabOrder = 10
        Text = '0'
      end
      object ED_BSPS7: TEdit
        Left = 16
        Top = 340
        Width = 41
        Height = 21
        TabOrder = 11
        Text = '0,0'
      end
      object GBD_BSPS14: TGroupBox
        Left = 520
        Top = 148
        Width = 249
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1057#1059' '#1052#1072#1082#1077#1090#1072' (2)'
        TabOrder = 12
        object D_BSPS14: TCheckListBox
          Left = 8
          Top = 16
          Width = 233
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - f '#1074#1088#1072#1097'. '#1074#1072#1083#1072' '#1043#1055#1063' '#1085#1080#1078#1077' '#1076#1086#1087#1091#1089#1090'.'
            '6'#1088' - f '#1074#1088#1072#1097'. '#1074#1072#1083#1072' '#1043#1055#1063' '#1085#1080#1078#1077' '#1087#1091#1089#1082#1086#1074'.'
            '5'#1088' - U'#1079#1087#1090' '#1085#1080#1078#1077' '#1085#1086#1088#1084#1099
            '4'#1088' - '#1043#1086#1090#1086#1074#1085'. '#1074#1099#1087#1088#1103#1084'.'
            '3'#1088' - '#1055#1086#1087#1099#1090#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1074#1099#1087#1088#1103#1084'.'
            '2'#1088' - '#1043#1086#1090#1086#1074#1085#1086#1089#1090#1100' '#1080#1085#1074#1077#1088#1090'. ('#1072#1074#1090'. '#1088#1077#1078'.)'
            '1'#1088' - '#1055#1086#1087#1099#1090#1082#1072' '#1079#1072#1087#1091#1089#1082#1072' '#1080#1085#1074#1077#1088#1090'.'
            '0'#1088' - '#1057#1073#1088#1086#1089' '#1072#1074#1072#1088#1080#1080)
          ParentFont = False
          TabOrder = 0
        end
      end
      object GBD_BSPS15: TGroupBox
        Left = 776
        Top = 148
        Width = 273
        Height = 129
        Caption = #1044#1080#1072#1075#1085#1086#1089#1090#1080#1082#1072' '#1057#1059' '#1052#1072#1082#1077#1090#1072' (3)'
        TabOrder = 13
        object D_BSPS15: TCheckListBox
          Left = 8
          Top = 16
          Width = 259
          Height = 105
          BorderStyle = bsNone
          Color = clMenuBar
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ItemHeight = 13
          Items.Strings = (
            '7'#1088' - '#1055#1086#1087#1099#1090#1082#1072' '#1089#1073#1088#1086#1089#1072' '#1072#1074#1072#1088'. '#1087#1088#1086#1080#1079#1074#1077#1076#1077#1085#1072
            '6'#1088' - '#1055#1088#1086#1080#1079#1074#1086#1076'. '#1086#1089#1090#1072#1085#1086#1074' '#1074#1099#1087#1088#1103#1084#1080#1090#1077#1083#1103
            '5'#1088' - '#1054#1090#1082#1072#1079' '#1076#1072#1090#1095'. '#1090#1077#1084#1087#1077#1088'. '#1043#1055#1063
            '4'#1088' - '#1056#1077#1079#1077#1088#1074
            '3'#1088' - '#1056#1077#1079#1077#1088#1074
            '2'#1088' - '#1056#1077#1079#1077#1088#1074
            '1'#1088' - '#1056#1077#1079#1077#1088#1074
            '0'#1088' - '#1056#1077#1079#1077#1088#1074)
          ParentFont = False
          TabOrder = 0
        end
      end
    end
  end
end
